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

ll h(ll x, ll r, ll c) {
    if(r*r - (x-c)*(x-c) < 0) return -1;
    return sqrt(r*r - (x-c)*(x-c));
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<ll> x(n), r(n);
        for(ll& xi : x) cin >> xi;
        for(ll& ri : r) cin >> ri;

        map<ll,ll> best;

        for(int i = 0; i < n; i++) {
            
            ll cx = x[i], ch = r[i];

            while(ch >= 0) {
                best[cx] = max(best[cx],ch);
                cx++;
                ch = h(cx,r[i],x[i]);
            }

            cx = x[i], ch = r[i];

            while(ch >= 0) {
                best[cx] = max(best[cx],ch);
                cx--;
                ch = h(cx,r[i],x[i]);
            }
        }

        ll ans = 0;

        for(auto [x,h] : best) {
            ans += 2*h+1;
        }

        cout << ans << '\n';
    }
}
