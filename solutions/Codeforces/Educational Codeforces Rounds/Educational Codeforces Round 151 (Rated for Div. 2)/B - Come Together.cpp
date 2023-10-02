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

    int t;
    cin >> t;

    while(t--) {
        int xa,ya,xb,yb,xc,yc;
        cin >> xa >> ya >> xb >> yb >> xc >> yc;

        ll ans = 1;

        int b_hor = xb - xa;
        int c_hor = xc - xa;

        if(b_hor >= 0 && c_hor >= 0 || b_hor < 0 && c_hor < 0) {
            ans += min(abs(b_hor), abs(c_hor));
        }

        int b_vert = yb - ya;
        int c_vert = yc - ya;

        if(b_vert >= 0 && c_vert >= 0 || b_vert < 0 && c_vert < 0) {
            ans += min(abs(b_vert), abs(c_vert));
        }

        cout << ans << '\n';
    }
    
}