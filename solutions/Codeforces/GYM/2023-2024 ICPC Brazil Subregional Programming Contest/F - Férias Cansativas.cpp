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

    int d, c, r;
    cin >> d >> c >> r;

    vector<int> C(c), R(r);
    for(int&ci : C) cin >> ci;
    for(int&ri : R) cin >> ri;

    ll ans = r;
    d += accumulate(R.begin(), R.end(), 0);
    
    for(int ci : C) {
        if(ci <= d) {
            d -= ci;
            ans++;
        }else {
            break;
        }
    }

    cout << ans << '\n';
}