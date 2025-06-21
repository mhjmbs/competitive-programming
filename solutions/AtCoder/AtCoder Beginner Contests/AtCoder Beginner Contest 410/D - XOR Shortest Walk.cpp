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



int main() {
    fastio;
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<pii>> g(n+1);

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
    }

    vector<vector<int>> dp(n+1, vector<int>(1<<10));
    queue<pii> q;

    q.emplace(1, 0);
    dp[1][0] = 1;

    while(!q.empty()) {
        auto [u, x] = q.front();
        q.pop();

        for(auto [v,w] : g[u]) {
            if(dp[v][x^w]) continue;
            q.emplace(v, x^w);
            dp[v][x^w] = true;
        }
    }

    int ans = -1;

    for(int x = 1<<10; x >= 0; x--) {
        if(dp[n][x]) ans = x;
    }

    cout << ans << '\n';
}