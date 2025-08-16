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

struct Point{
    ll x;
    ll y;
};

ll cross(Point a, Point b) {
    return a.x*b.y - a.y*b.x;
}

ll dot(Point a, Point b) {
    return a.x*b.x + a.y*b.y;
}

int main() {
    fastio;

    int n;
    cin >> n;

    vector<Point> p;
    p.reserve(2*n);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if(x != 0 || y != 0) p.push_back({x,y});
    }

    n = p.size();

    sort(p.begin(), p.end(), [](Point a, Point b) {
        if(cross({1,0}, a) > 0 ^ cross({1,0}, b) > 0) return cross({1,0}, a) > 0;
        return cross(a,b) ? cross(a,b) > 0 : dot({1,0}, a) < dot({1,0}, b);
    });

    for(int i = 0; i < n; i++) p.push_back(p[i]);

    ll x = 0, y = 0, ans = 0;

    for(int i = 0, l = 0; i < 2*n; i++) {
        if(i-l+1 > n) {
            while(i != l && cross(p[i], p[l]) == 0) {
                x -= p[l].x;
                y -= p[l].y;
                l++;
                ans = max(ans, x*x + y*y);
            }
        }
        while(cross(p[i],p[l]) > 0 || cross(p[i], p[l]) == 0 && dot(p[i], p[l]) < 0) {
            x -= p[l].x;
            y -= p[l].y;
            l++;
            ans = max(ans, x*x + y*y);
        }
        x += p[i].x;
        y += p[i].y;
        ans = max(ans, x*x + y*y);
    }

    cout << ans << '\n';
}