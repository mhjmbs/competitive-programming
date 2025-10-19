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

ll f(ll n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    n = stoll(s);
    return n;
}

int main() {
    fastio;

    ll x, y;
    cin >> x >> y;

    for(int i = 3; i <= 10; i++) {
        ll ny = f(x+y);
        x = y;
        y = ny;
    }

    cout << y << '\n';
}