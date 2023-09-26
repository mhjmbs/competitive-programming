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

    int n;
    cin >> n;

    vector<vector<int>> d(n, vector<int>(n));
    vector<ll> dp(1<<n, 0);

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            cin >> d[i][j];
            dp[(1<<i) ^ (1<<j)] = d[i][j];
        }
    }

    ll ans = 0;

    for(int s = 0; s < dp.size(); s++) {
        for(int i = 0; i < n; i++) {
            if(s&(1<<i)) {
                for(int j = i+1; j < n; j++) {
                    if(s&(1<<j)) {
                        dp[s] = max(dp[s], dp[s ^ (1<<i) ^ (1<<j)] + d[i][j]);
                        ans = max(ans, dp[s]);
                    }
                }
            }
        }
    }

    cout << ans << '\n';
}