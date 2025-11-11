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

ll n, k;

ll solve(ll u, ll r, ll d, ll l) {
    return (r-l+1) * (u-d+1);
}

ll solve_square(ll l1, ll l2) {
    if(l1 > l2) swap(l1,l2);
    int moves = min(k,l2-l1);
    l1 += moves;
    k -= moves;
    return (l1+k/2) * (l2+(k+1)/2);
}

int main() {
    fastio;

    cin >> n >> k;

    vector<pll> kings(n);
    for(auto& [x,y] : kings) cin >> x >> y;

    if(n == 1) {
        cout << 1 << '\n';
        return 0;
    }

    ll l = 1e6, u = -1e6, r = -1e6, d = 1e6;
    for(auto [x,y] : kings) {
        l = min(l,x);
        r = max(r,x);
        u = max(u,y);
        d = min(d,y);
    }

    ll ans = -1;

    for(auto [x,y] : kings) {
        int m1 = max(abs(l-x), abs(u-y));
        int m2 = max(abs(r-x), abs(u-y));
        int m3 = max(abs(l-x), abs(d-y));
        int m4 = max(abs(r-x), abs(d-y));

        if(min({m1,m2,m3,m4}) == m1) {
            if(k > m1) ans = max(ans,solve(y+k,   r,   d, x-k));
        }else if(min({m2,m3,m4}) == m2) {
            if(k > m2) ans = max(ans,solve(y+k, x+k,   d,   l));
        }else if(min({m3,m4}) == m3) {
            if(k > m3) ans = max(ans,solve(  u,   r, y-k, x-k));
        }else {
            if(k > m4) ans = max(ans,solve(  u, x+k, y-k,   l));
        }
    }

    ans = max(ans, solve_square((r-l+1), (u-d+1)));

    cout << ans << '\n';
}