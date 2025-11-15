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

struct Rectangle {
    Point dl, ur;
};

ll area(Rectangle r) {
    return (r.ur.x-r.dl.x+1)*(r.ur.y-r.dl.y+1);
}

bool is_adjacent(Rectangle a, Rectangle b) {
    return
        a.ur.y+1 == b.dl.y && a.dl.x <= b.ur.x && b.dl.x <= a.ur.x || 
        a.ur.x+1 == b.dl.x && a.dl.y <= b.ur.y && b.dl.y <= a.ur.y ||
        a.dl.y-1 == b.ur.y && a.dl.x <= b.ur.x && b.dl.x <= a.ur.x ||
        a.dl.x-1 == b.ur.x && a.dl.y <= b.ur.y && b.dl.y <= a.ur.y;
}

ll dfs(int u, vector<Rectangle>& rec, vector<int>& vis) {
    vis[u] = true;
    ll ans = area(rec[u]);

    for(int v = 0; v < rec.size(); v++) {
        if(!vis[v] && is_adjacent(rec[u],rec[v])) ans += dfs(v, rec, vis);
    }

    return ans;
}

void apply_x(int i, vector<Rectangle>& rec, ll a, ll b) {
    auto& r = rec[i];    
    if(r.ur.x < a) {
        r.dl.y -= b;
        r.ur.y -= b;
    }else if(a <= r.dl.x) {
        r.dl.y += b;
        r.ur.y += b;    
    }else {
        Rectangle lr = {r.dl,{a-1,r.ur.y}};
        Rectangle rr = {{a,r.dl.y},r.ur};
        lr.dl.y -= b;
        lr.ur.y -= b;

        r = lr;
        rec.push_back(rr);
    }
}

void apply_y(int i, vector<Rectangle>& rec, ll a, ll b) {
    auto& r = rec[i];
    if(r.ur.y < a) {
        r.dl.x -= b;
        r.ur.x -= b;
    }else if(a <= r.dl.y) {
        r.dl.x += b;
        r.ur.x += b;    
    }else {
        Rectangle lr = {r.dl,{r.ur.x,a-1}};
        Rectangle rr = {{r.dl.x,a},r.ur};
        lr.dl.x -= b;
        lr.ur.x -= b;

        r = lr;
        rec.push_back(rr);
    }
}

int main() {
    fastio;

    int n, x, y;
    cin >> n >> x >> y;

    vector<Rectangle> rec = { {{0,0}, {x-1,y-1}} };

    while(n--) {
        char type;
        ll a, b;
        cin >> type >> a >> b;

        for(int i = 0; i < rec.size(); i++) {
            auto& r = rec[i];
            if(type == 'X') apply_x(i, rec, a, b);
            else apply_y(i, rec, a, b);
        }
    }
    
    vector<ll> ans;
    vector<int> vis(rec.size());
    for(int i = 0; i < rec.size(); i++) {
        if(!vis[i]) ans.push_back(dfs(i,rec,vis));
    }
    
    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for(ll x : ans) cout << x << ' ';
    cout << '\n';
}