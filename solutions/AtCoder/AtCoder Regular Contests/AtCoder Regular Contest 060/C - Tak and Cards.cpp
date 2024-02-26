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



int main() {
    fastio;

    int n, a;
    cin >> n >> a;

    vector<ll> x(n+1);
    for(int i = 1; i <= n; i++) cin >> x[i];

    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(n+1, vector<ll>(a*n+1, 0)));
    
    for(int i = 0; i <= n; i++) dp[i][0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int count = 1; count <= n; count++) {
            for(int sum = 0; sum <= a*n; sum++) {
                dp[i][count][sum] = dp[i-1][count][sum];
                if(sum-x[i] >= 0) dp[i][count][sum] += dp[i-1][count-1][sum-x[i]];
            }
        }
    }

    ll ans = 0;

    for(int count = 1; count <= n; count++) {
        ans += dp[n][count][a*count];
    }

    cout << ans << '\n';
}