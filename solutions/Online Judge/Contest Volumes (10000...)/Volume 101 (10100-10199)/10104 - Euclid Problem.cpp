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

tiii egcd(int a, int b) {
    int x = 1, y = 0, x1 = 0, y1 = 1;
    while(b != 0) {
        int q = a/b;
        tie(x, x1) = make_tuple(x1, x - q*x1);
        tie(y, y1) = make_tuple(y1, y - q*y1);
        tie(a, b) = make_tuple(b, a%b);
    }
    return {a,x,y};
}

int main() {
    fastio;

    int a, b;

    while(cin >> a && cin >> b) {
        tiii ans = egcd(a,b);
        cout << get<1>(ans) << ' ' << get<2>(ans) << ' ' << get<0>(ans) << '\n';
    }
}