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

struct Point {
    int x;
    int y;

    Point(int x, int y) : x{x}, y{y} {}

    int dot(Point other) {
        return x*other.x + y*other.y;
    }

    Point operator-(Point other) {
        return {x-other.x, y-other.y};
    }

    bool operator==(Point other) {
        return x == other.x && y == other.y;
    }
};

bool solve(Point l, Point r, Point d, Point u) {
    return r-u == d-l && r-d == u-l &&
        (r-u).dot((r-u)) == (r-d).dot((r-d)) && (r-u).dot((r-d)) == 0;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int l, r, d, u;
        cin >> l >> r >> d >> u;
        bool yes = solve(Point(-l,0),Point(r,0),Point(0,-d),Point(0,u));
        cout << (yes ? "Yes" : "No") << '\n';
    }
}
