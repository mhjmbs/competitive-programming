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

    vector<int> b(n);
    for(int &bi : b) cin >> bi;

    vector<vector<int>> dp(n, vector<int>(2));

    dp[0][0] = b[0] == 0;
    dp[0][1] = b[0] == 1;

    for(int i = 1; i < n; i++) {
        if(b[i] == 1) {
            dp[i][0] = dp[i-1][1];
            dp[i][1] = dp[i-1][0] + 1;
        }else {
            dp[i][0] = dp[i-1][0] + 1;
            dp[i][1] = dp[i-1][1];
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += dp[i][1];
    }

    cout << ans << '\n';
}