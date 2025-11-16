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

ll ceil_div(ll a, ll b) {
    ll ans = a/b;
    if(ans*b != a) ans += (a>0)==(b>0);
    return ans;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        ll x, y, k;
        cin >> x >> y >> k;

        if(y == 1) {
            cout << -1 << '\n';
            continue;
        }

        while(x > 0) {
            if((k-1)/(y-1) == 0) break;
            ll group = min(x, ceil_div(y-k, (k-1)/(y-1)) + y - 1);
            k += group*((k-1)/(y-1));
            x -= group;
            if(k > 1e12) break;
        }

        cout << (k <= 1e12 ? k : -1) << '\n';
    }
}