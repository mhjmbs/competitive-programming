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

int n;
vector<ll> x;
vector<vector<pii>> g;
ll ans = 0;

void dfs(int u, int p) {
    for(auto [v,w] : g[u]) {
        if(v == p) continue;
        dfs(v, u);
        ans += w*abs(x[v]);
        x[u] += x[v];
        x[v] = 0;
    }
}

int main() {
    fastio;

    cin >> n;

    x.resize(n+1);
    for(int u = 1; u <= n; u++) cin >> x[u];

    g.resize(n+1);
    for(int m = 0; m < n-1; m++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }

    dfs(1, 0);

    cout << ans << '\n';
}