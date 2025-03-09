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
    ll x;
    ll y;
};

ll cross(Point a, Point b) {
    return a.x*b.y - a.y*b.x;
}

int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> l(n), r(n);

    for(int& li : l) cin >> li;
    for(int& ri : r) cin >> ri;

    vector<Point> hull;
    hull.reserve(n);

    hull.push_back({0,r[0]});
    hull.push_back({1,r[1]});

    for(int i = 2; i < n; i++) {
        Point p1 = hull[hull.size()-2];
        Point p2 = hull[hull.size()-1];
        Point p3 = {i,r[i]};

        while(cross({p2.x-p1.x, p2.y - p1.y},{p3.x-p2.x, p3.y-p2.y}) < 0) {
            hull.pop_back();
            if(hull.size() == 1) break;
            p1 = hull[hull.size()-2];
            p2 = hull[hull.size()-1];

        }

        hull.push_back(p3);
    }

    bool yes = true;

    for(int i = 0, j = 0; i < n; i++) {
        if(i == hull[j].x) {
            j++;
        }else {
            Point p1 = hull[j-1];
            Point p2 = hull[j];
            
            double a = double(p1.y-p2.y)/(p1.x-p2.x);
            double b = p1.y - a*p1.x;
            yes = yes && a*i + b > l[i];
        }
    }

    cout << (yes ? "Yes" : "No") << '\n';
}
