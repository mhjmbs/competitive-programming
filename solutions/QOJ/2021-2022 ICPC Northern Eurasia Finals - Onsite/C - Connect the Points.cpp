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
    ll x, y;
};

struct Line {
    Point a, b;
};

vector<Point> p(3);
ll ans = 1e18;
vector<Line> l;

bool solve() {
    vector<Line> cl;
    cl.push_back({p[0],p[0]});
    
    cl[0].a.x = min({p[0].x, p[1].x, p[2].x});
    cl[0].b.x = max({p[0].x, p[1].x, p[2].x});

    if(p[0].y != p[1].y) {
        cl.push_back( {p[1], {p[1].x, p[0].y} } );
    }

    if(p[0].y != p[2].y) {
        cl.push_back( {p[2], {p[2].x, p[0].y} } );
    }

    ll curr_ans = 0;
    for(auto [a,b] : cl) {
        curr_ans += abs(a.x-b.x) + abs(a.y-b.y);
    }

    if(curr_ans < ans) {
        ans = curr_ans;
        l = cl;
        return true;
    }

    return false;
}

void transf(Point& p) {
    swap(p.x,p.y);
}

void backtracking(int i = 0) {
    if(i == 3) {
        solve();
        for(auto& pi : p) transf(pi);
        if(solve()) {
            for(auto& [a,b] : l) {
                transf(a);
                transf(b);
            }
        }
        for(auto& pi : p) transf(pi);
        return;
    }

    for(int j = i; j < 3; j++) {
        swap(p[i],p[j]);
        backtracking(i+1);
        swap(p[i],p[j]);
    }
}

int main() {
    fastio;

    for(auto& [x,y] : p) cin >> x >> y;

    backtracking();

    cout << l.size() << '\n';
    for(auto [a,b] : l) {
        cout << a.x << ' ' << a.y << ' ' << b.x << ' ' << b.y << '\n';
    }
}