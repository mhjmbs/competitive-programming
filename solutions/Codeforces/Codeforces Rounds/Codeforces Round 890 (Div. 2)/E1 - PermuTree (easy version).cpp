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

int n;
ll ans = 0;
vector<vector<int>> adjacencies;

int dfs(int node, int last) {
    vector<ll> subtrees;
    subtrees.reserve(adjacencies[node].size());

    ll tot = 0;

    for(int adj : adjacencies[node]) {
        if(adj == last) continue;
        subtrees.push_back(dfs(adj, node));
        tot += subtrees.back();
    }

    
    vector<int> dp(tot+1, false);
    dp[0] = true;
    ll best = 0;

    for(int x : subtrees) {
        for(ll a = tot; a >= 0; a--) {
            if(a-x >= 0) dp[a] = dp[a] || dp[a-x];
            if(dp[a]) best = max(best, a*(tot-a));
        }
    }

    ans += best;

    return tot+1;
}

int main() {
    fastio;

    cin >> n;
    adjacencies.resize(n+1);

    for(int i = 2; i <= n; i++) {
        int pi;
        cin >> pi;
        adjacencies[pi].push_back(i);
    }

    dfs(1,-1);

    cout << ans << '\n';
}