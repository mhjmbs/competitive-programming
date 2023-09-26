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

    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);

    for(int &ai : a) cin >> ai;
    for(int &bi : b) cin >> bi;
    for(int &ci : c) cin >> ci;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    int ans = 0;
    int ia = 0, ib = 0, ic = 0;

    while(true) {

        if(ia >= n) {
            break;
        }

        while(ib < n && a[ia] >= b[ib]) {
            ib++;
        }

        if(ib >= n) {
            break;
        }

        while(ic < n && b[ib] >= c[ic]) {
            ic++;
        }

        if(ic >= n) {
            break;
        }

        ans++;
        ia++;
        ib++;
        ic++;
    }

    cout << ans << '\n';
}