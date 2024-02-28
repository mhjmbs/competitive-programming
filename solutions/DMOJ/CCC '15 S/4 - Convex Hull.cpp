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

int k, n, m;
int a, b;
vector<vector<tiii>> adjacencies;

int main() {
    fastio;

    cin >> k >> n >> m;

    adjacencies.resize(n+1);
    
    for(int i = 0; i < m; i++) {
        int ai, bi, ti, hi;
        cin >> ai >> bi >> ti >> hi;
        adjacencies[ai].emplace_back(bi, ti, hi);
        adjacencies[bi].emplace_back(ai, ti, hi);
    }

    cin >> a >> b;

    vector<vector<ll>> dp(n+1, vector<ll>(k+1, 1e15));
    vector<vector<int>> vis(n+1, vector<int>(k+1, false));
    priority_queue<tiii, vector<tiii>, greater<tiii>> prioq;

    dp[a][0] = 0;
    prioq.emplace(0,0,a);

    while(!prioq.empty()) {
        auto [dist,cost,node] = prioq.top();
        prioq.pop();

        if(vis[node][cost]) continue;

        for(auto [adj, edge, edgeCost] : adjacencies[node]) {
            if(cost+edgeCost >= k) continue;
            if(!vis[adj][cost+edgeCost] && dist+edge < dp[adj][cost+edgeCost]) {
                dp[adj][cost+edgeCost] = dist+edge;
                prioq.emplace(dp[adj][cost+edgeCost], cost+edgeCost, adj);
            }
        }

        vis[node][cost] = true;
    }

    ll ans = *min_element(dp[b].begin(), dp[b].begin()+k);

    if(ans == 1e15) cout << -1 << '\n';
    else cout << ans << '\n';
}