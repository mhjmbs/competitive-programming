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

    ll n, x, y;
    cin >> n >> x >> y;

    vector<ll> a(n);
    for(ll& ai : a) cin >> ai;
    sort(a.begin(), a.end());

    ll prop = lcm(x,y);
    ll xc = prop/x, yc = prop/y;

    ll w = a[0]*y;
    ll ans = a[0];

    for(int i = 1; i < n; i++) {
        int l = 0, r = a[i], curr = -1;
        while(l <= r) {
            int m = (l+r)/2;

            if(x*(a[i]-m) + y*m == w) {
                curr = m;
                break;
            }else if(x*(a[i]-m) + y*m < w) {
                l = m+1;
            }else {
                r = m-1;
            }
        }

        if(curr == -1) {
            cout << -1 << '\n';
            return 0;
        }

        ans += curr;
    }

    cout << ans << '\n';
}