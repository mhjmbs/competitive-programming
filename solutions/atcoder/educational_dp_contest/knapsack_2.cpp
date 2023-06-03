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

    int N, W;
    cin >> N >> W;

    vector<int> w(N+1), v(N+1);
    for(int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    vector<vector<ll>> dp(N+1, vector<ll>(int(1e5+1), ll(1e14)));

    for(int i = 0; i <= N; i++) {
        dp[i][0] = 0;
    }
    int ans = 0;

    for(int i = 1; i <= N; i++) {
        for(int curr_v = 1; curr_v < int(1e5+1); curr_v++) {
            dp[i][curr_v] = dp[i-1][curr_v];
            if(curr_v - v[i] >= 0) {
                dp[i][curr_v] = min(dp[i][curr_v], dp[i-1][curr_v-v[i]] + w[i]);
            }
            
            if(dp[i][curr_v] <= W) {
                ans = max(ans, curr_v);
            }
        }
    }

    cout << ans << '\n';
}