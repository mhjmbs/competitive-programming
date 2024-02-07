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

ll f(ll b, ll n) {
    if(n < b) return n;
    return f(b, n/b) + n % b;
}

int main() {
    fastio;

    ll n, s;
    cin >> n >> s;

    ll ans = LONG_LONG_MAX;

    for(ll b = 2; b <= sqrt(n); b++) {
        if(f(b,n) == s) ans = min(ans, b);
    }

    for(ll d1 = 1; d1 < sqrt(n); d1++) {
        ll d0 = s - d1;

        if(d0 < 0 || (n-d0)%d1 != 0) continue;
        
        ll b = (n-d0)/d1;
        
        if(d0 < b && d1 < b) ans = min(ans, b);
    }

    if(ans == LONG_LONG_MAX && s == n) ans = n+1;

    cout << (ans != LONG_LONG_MAX ? ans : -1) << '\n';
}