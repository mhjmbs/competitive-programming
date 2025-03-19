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

    ll n;
    cin >> n;

    ll ans_d = -1;
    ll ans_y = -1;

    for(__int128_t d = 1; d <= 1e6; d++) {
        __int128_t l = 1, r = 1e9, y = -1;
        
        while(l <= r) {
            __int128_t mid = (l+r)/2;

            __int128_t result = d*d*d + 3*d*d*mid + 3*d*mid*mid;

            if(result == n) {
                y = mid;
                break;
            }else if(result < n) {
                l = mid+1;
            }else {
                r = mid-1;
            }
        }

        if(y != -1) {
            ans_d = d;
            ans_y = y;
            break;
        }
    }

    if(ans_d == -1) {
        cout << -1 << '\n';
        return 0;
    }

    cout << ans_d + ans_y << ' ' << ans_y << '\n';
}