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

int n, m;
vector<vector<tiii>> g;
vector<int> vis;

bool dfs(int u, int i) {
    vis[u] = true;

    bool ok = u == n;

    for(auto [v, w, on] : g[u]) {
        if(!on || vis[v] || (w&(1<<i))) continue;
        ok = ok || dfs(v, i);
    }

    return ok;
}

int main() {
    fastio;

    cin >> n >> m;

    g.resize(n+1);

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w, 1);
        g[v].emplace_back(u, w, 1);
    }

    vis.resize(n+1, 0);

    int ans = (1<<30)-1;

    for(int i = 29; i >= 0; i--) {
        if(dfs(1, i)) {
            ans -= (1<<i);
            for(int u = 1; u <= n; u++) {
                for(auto& [v, w, on] : g[u]) on = on && !(w&(1<<i));
            }
        }
        fill(vis.begin(), vis.end(), 0);
    }

    cout << ans << '\n';
}