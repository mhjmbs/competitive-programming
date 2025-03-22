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

    ll n, q;
    cin >> n >> q;

    ll l = 0, r = n;

    while(q--) {
        ll d;
        cin >> d;

        l += d;
        r += d;

        if(l < 0) l = 0;
        if(l > n) l = n;
        if(r < 0) r = 0;
        if(r > n) r = n;
    }

    if(l == r) cout << l << '\n';
    else cout << "uncertain\n";
}