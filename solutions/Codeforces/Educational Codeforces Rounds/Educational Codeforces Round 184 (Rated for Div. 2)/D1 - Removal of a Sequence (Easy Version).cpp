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

bool check(ll num, ll x, ll y, ll k) {
    ll ord = num;

    for(int i = 0; i < x; i++) {
        ord -= ord/y;
    }
    
    return ord >= k;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        ll x, y, k;
        cin >> x >> y >> k;

        ll l = 1, r = 1e12, ans = -1;

        while(l <= r) {
            ll mid = (l+r)/2;

            if(check(mid, x, y, k)) {
                ans = mid;
                r = mid-1;
            }else {
                l = mid+1;
            }
        }

        cout << ans << '\n';
    }
}