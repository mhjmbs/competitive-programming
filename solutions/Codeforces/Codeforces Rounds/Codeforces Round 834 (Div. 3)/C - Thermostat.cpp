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
        int l, r, x, a, b;
        cin >> l >> r >> x >> a >> b;

        int ans = -1;

        if(a == b) {
            ans = 0;
        }else if(abs(a-b) >= x) {
            ans = 1;
        }else if(abs(a-l) >= x && abs(l - b) >= x ||
                 abs(a-r) >= x && abs(r - b) >= x) {
            ans = 2;
        }else if(abs(a-l) >= x && abs(l-r) >= x && abs(r-b) >= x ||
                 abs(a-r) >= x && abs(r-l) >= x && abs(l-b) >= x) {
            ans = 3;
        }

        cout << ans << '\n';
    }
}