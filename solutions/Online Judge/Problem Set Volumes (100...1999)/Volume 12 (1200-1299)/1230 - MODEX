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

ll bin_expo(ll x, ll y, ll n) {
    ll ans = 1;

    while(y != 0) {
        if(y&1) {
            ans = (ans * x) % n;
        }
        y >>= 1;
        x = (x*x) % n;
    }

    return ans;
}

int main() {
    fastio;

    int c;
    cin >> c;

    for(int i = 0; i < c; i++) {
        ll x, y, n;
        cin >> x >> y >> n;
        cout << bin_expo(x, y, n) << '\n';
    }

    cin >> c;
}