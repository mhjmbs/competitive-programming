#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class flow_t, class cost_t> struct min_cost {
	static constexpr flow_t FLOW_EPS = flow_t(1e-10);
	static constexpr flow_t FLOW_INF = numeric_limits<flow_t>::max();
	static constexpr cost_t COST_EPS = cost_t(1e-10);
	static constexpr cost_t COST_INF = numeric_limits<cost_t>::max();
	int n, m{}; vector<int> ptr, nxt, zu;
	vector<flow_t> capa; vector<cost_t> cost;
	min_cost(int N) : n(N),ptr(n,-1),dist(n),vis(n),pari(n) {}
	void add_edge(int u, int v, flow_t w, cost_t c) {
		nxt.push_back(ptr[u]); zu.push_back(v); capa.push_back(w); cost.push_back(c); ptr[u] = m++;
		nxt.push_back(ptr[v]); zu.push_back(u); capa.push_back(0); cost.push_back(-c); ptr[v] = m++;
	}
	vector<cost_t> pot, dist; vector<bool> vis; vector<int> pari;
	vector<flow_t> flows; vector<cost_t> slopes;
	// You can pass t = -1 to find a shortest
	void shortest(int s, int t) {//path to each vertex. ///start-hash
		using E = pair<cost_t, int>;
		priority_queue<E, vector<E>, greater<E>> que;
		for(int u = 0; u < n; ++u){dist[u]=COST_INF; vis[u]=false;}
		for (que.emplace(dist[s] = 0, s); !que.empty(); ) {
			const cost_t c = que.top().first;
			const int u = que.top().second; que.pop();
			if (vis[u]) continue;
			vis[u] = true; if (u == t) return;
			for (int i = ptr[u]; ~i; i = nxt[i]) if (capa[i] > FLOW_EPS) {
				const int v = zu[i];
				const cost_t cc = c + cost[i] + pot[u] - pot[v];
				if(dist[v] > cc){que.emplace(dist[v]=cc,v);pari[v]=i;}
			}
		}
	}///end-hash
	auto run(int s, int t, flow_t limFlow = FLOW_INF) { ///start-hash
		pot.assign(n, 0); flows = {0}; slopes.clear();
		while (true) {
			bool upd = false;
			for (int i = 0; i < m; ++i) if (capa[i] > FLOW_EPS) {
				const int u = zu[i ^ 1], v = zu[i];
				const cost_t cc = pot[u] + cost[i];
				if(pot[v] > cc + COST_EPS) { pot[v] = cc; upd = true; }
			} if (!upd) break;
		}
		flow_t flow = 0; cost_t tot_cost = 0;
		while (flow < limFlow) {
			shortest(s, t); flow_t f = limFlow - flow;
			if (!vis[t]) break;
			for(int u = 0; u < n; ++u)pot[u] += min(dist[u],dist[t]);
			for (int v = t; v != s; ) { const int i = pari[v];
				if (f > capa[i]) { f = capa[i]; } v = zu[i^1];
			}
			for (int v = t; v != s; ) { const int i = pari[v];
				capa[i] -= f; capa[i^1] += f; v = zu[i^1];
			}
			flow += f; tot_cost += f * (pot[t] - pot[s]);
			flows.push_back(flow); slopes.push_back(pot[t] - pot[s]);
		} return make_pair(flow, tot_cost);
	} ///end-hash
};

int n, m, s;



int main() {
    fastio;

    cin >> n >> m >> s;

    
    vector<string> grid(n);
    for(string& line : grid) cin >> line;
    
    int S = 0;
    int T = 1;
    int N = 2;

    vector<vector<int>> idw(n, vector<int>(m));
    vector<vector<pii>> idb(n, vector<pii>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] != '0') {
                idw[i][j] = N++;
                N++;
                grid[i][j]--;
            }else {
                idb[i][j] = {N++, N++};
                N += 2;
                grid[i][j] = 'B';
            }
        }
    }

    min_cost<int,int> mc(N);

    vector<int> ver, hor;

    for(int count = 0; count < s; count++) {
        char type;
        int i, j, d;
        cin >> type >> i >> j >> d;
        i--,j--;

        if(type == 'H') {
            int count = 0;
            for(int j2 = j+1; j2 < m && grid[i][j2] != 'B'; j2++) {
                count++;
                mc.add_edge(idb[i][j].first, idw[i][j2], grid[i][j2]-'0', -1);
                mc.add_edge(idb[i][j].first, idw[i][j2], 8-(grid[i][j2]-'0'), 1);
            }
            mc.add_edge(S, idb[i][j].first, d-count, 0);
            hor.push_back(mc.m-2);
        }else {
            int count = 0;
            for(int i2 = i+1; i2 < n && grid[i2][j] != 'B'; i2++) {
                count++;
                mc.add_edge(idw[i2][j], idb[i][j].second, 1e8, 0);
            }
            mc.add_edge(idb[i][j].second, T, d-count, 0);
            ver.push_back(mc.m-2);
        }
    }

    auto [flow,cost] = mc.run(S,T);

    int bla = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] != 'B') bla += grid[i][j]-'0';
        }
    }

    if(any_of(ver.begin(), ver.end(), [&mc](int e) { return mc.capa[e] != 0; }) ||
       any_of(hor.begin(), hor.end(), [&mc](int e) { return mc.capa[e] != 0; })) {
        cout << "IMPOSSIBLE\n";
    }else {
        cout << bla+cost << '\n';
    }
}