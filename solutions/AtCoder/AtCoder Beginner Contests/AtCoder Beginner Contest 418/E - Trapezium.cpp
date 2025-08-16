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

bool operator<(Point a, Point b) {
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool operator==(Point a, Point b) {
    return a.x == b.x && a.y == b.y;
}

ll cross(Point a, Point b) {
    return a.x*b.y - b.x*a.y;
}

ll dot(Point a, Point b) {
    return a.x*b.x + a.y*b.y;
}

int main() {
    fastio;

    ll n;
    cin >> n;

    vector<Point> p(n);
    for(auto& [x,y] : p) cin >> x >> y;

    sort(p.begin(), p.end(), [](Point a, Point b) {
        if(a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    vector<Point> v;
    v.reserve(n*(n-1)/2);
    
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            v.push_back({p[j].x - p[i].x, p[j].y - p[i].y});
        }
    }
    
    sort(v.begin(), v.end(), [](Point a, Point b) {
        if(cross({1,0}, a) < 0 ^ cross({1,0}, b) < 0) {
            return cross({1,0}, a) >= 0;
        }
        return cross(a,b) != 0 ? cross(a,b) > 0 : a < b;
    });
    
    ll ans = 0, bad = 0;
    ll dir = 1, eq = 1;

    for(int i = 1; i < n*(n-1)/2; i++) {
        if(v[i-1] != v[i]) {
            bad += eq*(eq-1)/2;
            eq = 0;
        }
        if(!(cross(v[i-1], v[i]) == 0 && dot(v[i-1],v[i]) > 0)) {
            ans += dir*(dir-1)/2;
            dir = 0;
        }
        eq++;
        dir++;
    }

    cout << ans - bad/2 << '\n';
}