#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

template<class flow_t, class cost_t> struct min_cost {
    static constexpr flow_t FLOW_EPS = 1e-10L;
    static constexpr flow_t FLOW_INF = std::numeric_limits<flow_t>::max();
    static constexpr cost_t COST_EPS = 1e-10L;
    static constexpr cost_t COST_INF = std::numeric_limits<cost_t>::max();
    int n, m;
    vector<int> ptr, nxt, zu;
    vector<flow_t> capa;
    vector<cost_t> cost;
    explicit min_cost (int n_) : n(n_), m(0), ptr(n_, -1) {}
    void add_edge(int u, int v, flow_t w, cost_t c) {
        nxt.push_back(ptr[u]); zu.push_back(v); capa.push_back(w);
            cost.push_back(c); ptr[u] = m++;
        nxt.push_back(ptr[v]); zu.push_back(u); capa.push_back(0);
            cost.push_back(-c); ptr[v] = m++;
    }
    vector<cost_t> pot, dist;
    vector<bool> vis;
    vector<int> pari;
    vector<flow_t> flows; vector<cost_t> slopes;
    void shortest(int s, int t) {
        using Entry = pair<cost_t, int>;
        priority_queue<Entry, vector<Entry>, std::greater<Entry>> que;
        for(int u = 0; u < n; ++u) {dist[u] = COST_INF; vis[u] = false; }
        for(que.emplace(dist[s] = 0, s); !que.empty(); ) {
            const cost_t c = que.top().first;
            const int u = que.top().second;
            que.pop();
            if (vis[u]) continue;
            vis[u] = true;
            if(u == t) return;
            for(int i = ptr[u]; ~i; i=nxt[i]) if(capa[i] > FLOW_EPS) {
                const int v = zu[i];
                const cost_t cc = c + cost[i] + pot[u] - pot[v];
                if(dist[v] > cc) { que.emplace(dist[v] = cc, v); pari[v] = i;}
            }
        }
    }
    pair<flow_t, cost_t> run(int s, int t, flow_t limFlow = FLOW_INF) {
        assert(0 <= limFlow);
        pot.assign(n, 0);
        while(true) {
            bool upd = false;
            for(int i = 0; i < m; i++) if(capa[i] > FLOW_EPS) {
                const int u = zu[i^1], v = zu[i];
                const cost_t cc = pot[u] + cost[i];
                if(pot[v] > cc + COST_EPS) {pot[v] = cc; upd = true;}
            }
            if(!upd) break;
        }
        dist.resize(n); vis.resize(n); pari.resize(n);
        flows.clear(); flows.push_back(0);
        slopes.clear();
        flow_t flow = 0; cost_t cost = 0;
        while(flow < limFlow) {
            shortest(s, t);
            if (!vis[t]) break;
            for(int u = 0; u < n; u++) pot[u] += min(dist[u], dist[t]);
            flow_t f = limFlow - flow;
            for(int v = t; v != s; ) {
                const int i = pari[v]; if(f > capa[i]) {f = capa[i];} v = zu[i ^ 1];
            }
            for(int v = t; v != s; ) {
                const int i = pari[v]; capa[i] -= f; capa[i ^1] +=f; v = zu[i ^ 1];
            }
            flow += f;
            cost += f * (pot[t] - pot[s]);
            flows.push_back(flow); slopes.push_back(pot[t] - pot[s]);
        }
        return {flow, cost};
    }
};

int main() {
    fastio;

    int n;
    cin >> n;

    string s;
    cin >> s;
    s = '-' + s;

    vector<int> b(n+1);
    for(int i = 1; i <= n; i++) cin >> b[i];

    vector<int> freq(27, 0);
    for(int i = 1; i <= n; i++) freq[s[i]-'a'+1]++;

    min_cost<int, int> mc(28 + 14*n);

    int sink = 0;
    int target = 28 + 14*n - 1;
    int choice = n + 27;

    for(int c = 1; c <= 26; c++) {
        mc.add_edge(sink, n+c, freq[c], 0);

        for(int i = 1; i <= n/2; i++) {
            mc.add_edge(n+c, choice, 1, 0);
            mc.add_edge(choice, i, 1, (s[i] == 'a' - 1 + c) ? -b[i] : 0);
            mc.add_edge(choice, n-i+1, 1, (s[n-i+1] == 'a' - 1 + c) ? -b[n-i+1] : 0);
            choice++;
        }
    }

    for(int i = 1; i <= n; i++) {
        mc.add_edge(i, target, 1, 0);
    }

    cout << -mc.run(sink, target).second << '\n';
}