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

ll m = 1e9+7;
vector<ll> fact;

ll binExp(ll a, ll b, ll m = LONG_LONG_MAX) {
    a %= m;
    ll ans = 1;
    while(b > 0) {
        if(b&1) ans = (ans * a) % m;
        b >>= 1;
        a = (a*a) % m;
    }
    return ans;
}

ll invMod(ll a, ll m) {
    return binExp(a, m-2, m);
}

ll p(ll x) {
    return fact[x];
}

ll pr(ll a, ll b, ll c) {
    return p(a)*invMod(p(b)*p(c), 1e9+7) % m;
}

int main() {
    fastio;

    ll h, w, a, b;
    cin >> h >> w >> a >> b;

    fact.resize(h+w+1);
    fact[0] = 1;
    for(int i = 1; i <= h+w; i++) fact[i] = fact[i-1] * i % m;

    ll r1 = h-a;
    ll c1 = b;
    ll r2 = h;
    ll c2 = w-b;

    ll ans = 0;

    for(ll r = 1; r <= r1; r++) {
        ans = (ans + pr(r-1+c1-1, r-1, c1-1) * pr(r2-(r-1)-1+c2-1, r2-(r-1)-1, c2-1)) % m; 
    }

    cout << ans << '\n';
}