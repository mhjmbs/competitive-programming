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



int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacencies(n+1);
    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adjacencies[u].push_back(v);
    }

    vector<int> in_degree(n+1, 0);
    for(int node = 1; node <= n; node++) {
        for(int adjacency : adjacencies[node]) {
            in_degree[adjacency]++;
        }
    }

    queue<int> q;
    for(int node = 1; node <= n; node++) {
        if(in_degree[node] == 0) {
            q.push(node);
        }
    }

    vector<int> dp(n+1, 0);
    int ans = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int adjacency : adjacencies[node]) {
            in_degree[adjacency]--;
            if(in_degree[adjacency] == 0) {
                q.push(adjacency);
            }
            dp[adjacency] = max(dp[adjacency], dp[node] + 1);
            ans = max(ans, dp[adjacency]);
        }
    }

    cout << ans << '\n';
}