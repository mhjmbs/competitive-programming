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

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<ll> a(n);
        for(ll& ai : a) cin >> ai;

        vector<ll> pref(n+1, 1);
        for(int i = 1; i <= n; i++) pref[i] = pref[i-1] * a[i-1];

        vector<vector<ll>> dp(n, vector<ll>(n, 0));

        for(int len = 3; len <= n; len++) {
            for(int l = 0; l+len <= n; l++) {
                int r = l+len-1;

                if(len == 3) {
                    dp[l][r] = a[l]*a[l+1]*a[r];
                    continue;
                }

                for(int i = l; i < r; i++) {
                    dp[l][r] = max(dp[l][r], dp[l][i]+dp[i+1][r]);
                }

                for(int i = l+1; i < r; i++) {
                    dp[l][r] = max(dp[l][r], a[l]*a[i]*a[r] + dp[l+1][i-1] + dp[i+1][r-1]);
                }
            }
        }

        cout << dp[0][n-1] << '\n';
    }
    
}