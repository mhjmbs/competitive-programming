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



int main() {
    fastio;

    int x1, y1, r1;
    cin >> x1 >> y1 >> r1;

    int x2, y2, r2;
    cin >> x2 >> y2 >> r2;

    double dist = sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
    double r3 = (r1+r2 - dist)/2;

    double x3 = (r1-r3)*(x2-x1)/dist + x1;
    double y3 = (r1-r3)*(y2-y1)/dist + y1;

    cout << setprecision(15) <<  x3 << ' ' << y3 << ' ' << r3 << '\n';
}