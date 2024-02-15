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
        ll k, x, a;
        cin >> k >> x >> a;

        bool yes = true;
        ll ca = a;
        for(int i = 1; i <= x+1; i++) {
            ll l = 1, r = ca, ans = -1;
            while(l <= r) {
                ll mid = (l+r)/2;

                if(ca + (k-1)*mid > a) {
                    ans = mid;
                    r = mid -1;
                }else {
                    l = mid+1;
                }
            }

            if(ans == -1) {
                yes = false;
                break;
            }

            ca -= ans;
        }

        cout << (yes ? "YES\n" : "NO\n");
    }
}