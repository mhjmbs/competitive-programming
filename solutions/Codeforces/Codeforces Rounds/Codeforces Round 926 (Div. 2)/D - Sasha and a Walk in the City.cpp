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

vector<vector<int>> adjacencies;
vector<vector<ll>> dp;
ll m = 998244353;

ll fastExp(ll a, ll b, ll m) {
    ll ans = 1;

    while(b > 0) {
        if(b&1) ans = ans*a % m;
        a = a*a % m;
        b >>= 1;
    }
    return ans;
}

void dfs(int node, int parent) {
    for(int adj : adjacencies[node]) {
        if(adj == parent) continue;
        dfs(adj, node);
    }

    dp[node] = {1,1,0};

    for(int adj : adjacencies[node]) {
        if(adj == parent) continue;
        dp[node][0] = dp[node][0] * dp[adj][0] % m;
        dp[node][1] = dp[node][1] * (dp[adj][0] + dp[adj][1]) % m;
    }

    for(int adj : adjacencies[node]) {
        if(adj == parent) continue;
        dp[node][2] = (dp[node][2] + dp[adj][2] * dp[node][0]*fastExp(dp[adj][0],m-2, m)) % m;
        dp[node][2] = (dp[node][2] + dp[adj][1] * dp[node][0]*fastExp(dp[adj][0],m-2, m)) % m;
    }

}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        adjacencies.assign(n+1, vector<int>());
        dp.assign(n+1, vector<ll>(3, 0));

        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            adjacencies[u].push_back(v);
            adjacencies[v].push_back(u);
        }

        dfs(1, -1);

        cout << (dp[1][0] + dp[1][1] + dp[1][2]) % m << '\n';
    }
}