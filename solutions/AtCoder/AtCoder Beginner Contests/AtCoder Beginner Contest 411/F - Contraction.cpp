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

struct Dsu {
    vector<int> p, h;
    vector<set<int>> g;
    int cnt;

    Dsu(int n, vector<vector<int>>& gv) : p(n), h(n), g(n), cnt{0} {
        iota(p.begin(), p.end(), 0);
        for(int u = 0; u < n; u++) {
            for(int v : gv[u]) {
                g[u].insert(v);
                cnt++;
            }
        }
    }

    int find(int u) {
        return (p[u] == u) ? u : p[u] = find(p[u]); 
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);

        if(u != v && g[u].count(v)) {
            if(h[u] < h[v]) swap(u,v);
            p[v] = u;
            h[u] = max(h[u], h[v]+1);

            for(int w : g[v]) {
                g[w].erase(v);
                cnt -= 2;
                if(w != u && !g[u].count(w)) {
                    g[w].insert(u);
                    g[u].insert(w);
                    cnt += 2;
                }
            }
            g[v].clear();
        }
    }
};

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n+1);
    vector<pii> edges(m+1);

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges[i] = {u,v};
    }

    int q;
    cin >> q;

    Dsu dsu(n+1, g);

    while(q--) {
        int x;
        cin >> x;

        auto [u,v] = edges[x];

        dsu.merge(u,v);

        cout << dsu.cnt/2 << '\n';
    }
}