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
};

bool attacks(Point a, Point b) {
    return
        a.x == b.x ||
        a.y == b.y ||
        abs(a.x-b.x) == abs(a.y-b.y);
}

Point vd1(Point a, Point b) {
    return {a.x, b.y-(b.x-a.x)};
}

Point vh(Point a, Point b) {
    return {a.x, b.y};
}

Point vd2(Point a, Point b) {
    return {a.x, b.y+(b.x-a.x)};
}

Point hd1(Point a, Point b) {
    return {b.x-(b.y-a.y), a.y};
}

Point hd2(Point a, Point b) {
    return {b.x+(b.y-a.y), a.y};
}

pair<bool,Point> d1d2(Point a, Point b) {
    int ba = a.y - a.x;
    int bb = b.y + b.x;
    if((bb-ba) % 2 != 0) return make_pair(false, Point{-1,-1});
    return make_pair(true, Point{(bb-ba)/2, (bb-ba)/2 + ba});
}

int main() {
    fastio;

    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<Point> p(n);
        for(auto& [x,y] : p) cin >> x >> y;
        
        int rel = -1;
        for(int i = 1; i < n; i++) {
            if(!attacks(p[0],p[i])) {
                rel = i;
            }
        }
        
        if(rel == -1) {
            cout << "YES\n" <<
            p[0].x << ' ' << p[0].y << '\n';
            continue;
        }
        
        vector<Point> ans;
        ans.push_back(vh(p[0],p[rel]));
        ans.push_back(vh(p[rel],p[0]));
        ans.push_back(vd1(p[0],p[rel]));
        ans.push_back(vd1(p[rel],p[0]));
        ans.push_back(vd2(p[0],p[rel]));
        ans.push_back(vd2(p[rel],p[0]));
        ans.push_back(hd1(p[0],p[rel]));
        ans.push_back(hd1(p[rel],p[0]));
        ans.push_back(hd2(p[0],p[rel]));
        ans.push_back(hd2(p[rel],p[0]));
        if(auto x = d1d2(p[0],p[rel]); x.first) {
            ans.push_back(x.second);
        }
        if(auto x = d1d2(p[rel],p[0]); x.first) {
            ans.push_back(x.second);
        }
        
        bool ok = true;
        for(Point ans : ans) {
            ok = true;
            for(Point pi : p) {
                if(!attacks(ans,pi)) ok = false;
            }
            if(ok) {
                cout << "YES\n" <<
                ans.x << ' ' << ans.y << '\n';
                break;
            }
        }
        
        if(!ok) cout << "NO\n";
    }
}