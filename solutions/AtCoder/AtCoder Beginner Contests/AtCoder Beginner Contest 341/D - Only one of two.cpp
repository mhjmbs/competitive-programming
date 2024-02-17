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

    ll n, m, k;
    cin >> n >> m >> k;

    ll l = 1, r = 1e18, ans = -1;
    while(l <= r) {
        ll mid = l + (r-l)/2;

        ll count = mid/n + mid/m - 2*(mid/lcm(n,m));

        if(count >= k) {
            ans = mid;
            r = mid-1;
        }else {
            l = mid+1;
        }
    }

    cout << ans << '\n';
}