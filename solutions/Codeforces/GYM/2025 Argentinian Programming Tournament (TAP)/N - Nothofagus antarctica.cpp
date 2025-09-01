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

    int n;
    cin >> n;

    int l = 1e9, r = -1e9, t = -1e9, b = 1e9;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        l = min(l, x);
        r = max(r, x);
        t = max(t, y);
        b = min(b, y);
    }

    cout << 2*(r-l+2+t-b+2) << '\n';
}