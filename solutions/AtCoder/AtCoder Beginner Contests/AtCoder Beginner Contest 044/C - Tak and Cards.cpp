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

    int n, a;
    cin >> n >> a;
    
    vector<int> x(n);
    for(int& xi : x) cin >> xi;

    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(n+1, vector<ll>(2501, 0)));
    dp[0][0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int taken = 0; taken <= n; taken++) {
            for(int sum = 0; sum <= 2500; sum++) {
                dp[i][taken][sum] = dp[i-1][taken][sum];
                if(taken-1 >= 0 && sum-x[i-1] >= 0) dp[i][taken][sum] += dp[i-1][taken-1][sum-x[i-1]];
            }
        }
    }

    ll ans = 0;
    for(int count = 1; count <= n; count++) {
        for(int sum = 0; sum <= 2500; sum++) {
            if(sum%count == 0 && sum/count == a) {
                ans += dp[n][count][sum];
            }
        }
    }

    cout << ans << '\n';
}