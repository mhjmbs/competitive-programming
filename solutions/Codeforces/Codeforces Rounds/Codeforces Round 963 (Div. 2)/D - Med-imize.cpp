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

int n, k;

bool ok(ll x, vector<int>& a) {
    vector<int> b(n);
    
    for(int i = 0; i < n; i++) {
        b[i] = a[i] >= x ? 1 : -1;
    }

    vector<int> dp(n, 0);
    dp[0] = b[0];

    for(int i = 1; i < n; i++) {
        if(i%k == 0) {
            dp[i] = max(dp[i-k], b[i]);
        }else {
            dp[i] = dp[i-1]+b[i];
            if(i >= k) dp[i] = max(dp[i], dp[i-k]);
        }
    }

    return dp[n-1] > 0;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> k;

        vector<int> a(n);
        for(int& ai : a) cin >> ai;

        ll l = 1, r = 1e9, ans = -1;

        while(l <= r) {
            ll mid = (l+r)/2;

            if(ok(mid, a)) {
                l = mid+1;
                ans = mid;
            }else {
                r = mid-1;
            }
        }

        cout << ans << '\n';
    }
}