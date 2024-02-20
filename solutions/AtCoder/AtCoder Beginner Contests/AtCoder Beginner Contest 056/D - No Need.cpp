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

ll Mod(ll a, ll m) {
    return (a%m+m)%m;
}

int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    vector<ll> a;

    for(int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        if(ai < k) a.push_back(ai);
    }

    vector<ll> dp(2*k, 0), dp2(2*k, 0);
    dp[0] = dp2[0] = 1;
    ll m1 = 1e9+7, m2 = 1011001110001111;

    for(int i = 0; i < a.size(); i++) {
        for(int sum = 2*k-1; sum >= a[i]; sum--) {
            dp[sum] = Mod(dp[sum] + dp[sum-a[i]], m1);
            dp2[sum] = Mod(dp2[sum] + dp2[sum-a[i]], m2);
        }
    }

    int ans = 0;

    for(int i = 0; i < a.size(); i++) {
        bool necessary = false;

        for(int sum = a[i]; sum < 2*k; sum++) {
            dp[sum] = Mod(dp[sum] - dp[sum-a[i]], m1);
            dp2[sum] = Mod(dp2[sum] - dp2[sum-a[i]], m2);
            if(sum >= k && sum-a[i] < k && (dp[sum-a[i]] != 0 || dp2[sum-a[i]] != 0)) necessary = true;
        }
        
        if(!necessary) ans++;

        for(int sum = 2*k-1; sum >= a[i]; sum--) {
            dp[sum] = Mod(dp[sum] + dp[sum-a[i]], m1);
            dp2[sum] = Mod(dp2[sum] + dp2[sum-a[i]], m2);
        }
    }

    cout << ans << '\n';
}