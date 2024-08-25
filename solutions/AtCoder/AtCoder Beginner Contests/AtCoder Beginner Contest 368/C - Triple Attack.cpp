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



int main() {
    fastio;

    ll n;
    cin >> n;

    set<pll> h;
    for(int i = 1; i <= n; i++) {
        ll hi;
        cin >> hi;
        h.emplace(i, hi);
    }

    ll t = 0;

    while(!h.empty()) {
        ll l = t+1, r = 1e18, ans = -1;

        while(l <= r) {
            ll mid = (l+r)/2;

            if(mid-t + 2*(mid/3 - t/3) >= h.begin()->second) {
                r = mid-1;
                ans = mid;
            }else {
                l = mid + 1;
            }
        }

        t = ans;
        h.erase(h.begin());
    }

    cout << t << '\n';
}