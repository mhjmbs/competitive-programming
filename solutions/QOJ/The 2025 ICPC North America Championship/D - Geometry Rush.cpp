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

int main() {
    fastio;
    
    int n, m, w, h;
    cin >> n >> m >> w >> h;
    
    vector<Point> u(n), d(m);
    for(auto& [x,y] : u) cin >> x >> y;
    for(auto& [x,y] : d) cin >> x >> y;
    
    vector<ll> c(w+1, h), f(w+1, -h);
    
    Point last = {0,h};
    for(int i = 0, x = 0; i < n; i++) {
        while(x < u[i].x) {
            ll ny = ceil( last.y + (u[i].y-last.y)*(x-last.x)/double(u[i].x-last.x) );
            c[x] = min(c[x], ny-1);
            x++;
        }
        c[x] = min(c[x], u[i].y-1);
        last = u[i];
    }

    last = {0,-h};
    for(int i = 0, x = 0; i < m; i++) {
        while(x < d[i].x) {
            ll ny = floor( last.y + (d[i].y-last.y)*(x-last.x)/double(d[i].x-last.x) );
            f[x] = max(f[x], ny+1);
            x++;
        }
        f[x] = max(f[x], d[i].y+1);
        last = d[i];
    }

    bool impossible = false;
    ll a = 0, b = 0;
    for(int x = 1; x <= w; x++) {
        b = min(b+1, c[x] - (x % 2 != abs(c[x] % 2)));
        a = max(a-1, f[x] + (x % 2 != abs(f[x] % 2)));
        if(a > b) impossible = true;
    }

    if(impossible) cout << "impossible\n";
    else cout << a << ' ' << b << '\n';
}