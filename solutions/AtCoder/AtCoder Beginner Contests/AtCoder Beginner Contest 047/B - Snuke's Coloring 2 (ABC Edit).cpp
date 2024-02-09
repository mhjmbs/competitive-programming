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

    int w, h, n;
    cin >> w >> h >> n;

    int up = h, down = 0, left = 0, right = w;

    for(int i = 0; i < n; i++) {
        int xi, yi, ai;
        cin >> xi >> yi >> ai;

        if(ai == 1) {
            left = max(left, xi);
        }else if(ai == 2) {
            right = min(right, xi);
        }else if(ai == 3) {
            down = max(down, yi);
        }else {
            up = min(up, yi);
        }
    }

    int ans;

    if(left > right || down > up) ans = 0;
    else ans = (right-left) * (up-down);

    cout << ans << '\n';
}