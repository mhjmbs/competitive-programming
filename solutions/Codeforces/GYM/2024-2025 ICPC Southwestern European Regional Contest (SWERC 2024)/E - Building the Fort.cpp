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



int main() {
    fastio;

    int n;
    cin >> n;

    vector<pii> p, ans;
    set<int> v;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p.emplace_back(x,y);
        v.insert(x);
    }

    for(int x : v) {
        if(x == 1) {
            p.emplace_back(x,1);
            if(v.count(2) == 0) p.emplace_back(x+1,2);
            continue;
        }

        if(x == *v.begin()) p.emplace_back(x-1,1);
        else p.emplace_back(x-1,2);

        p.emplace_back(x,2);
    }
    
    sort(p.begin(), p.end(), [](pii a, pii b) {
        auto [x1,y1] = a;
        auto [x2,y2] = b;
        if(y1 == 1 && y2 == 1) return x1 > x2;
        if(y1 == 1) return true;
        if(y2 == 1) return false;

        if(x1 == 1 && x2 == 1) return y1 < y2;
        if(y1 == 1) return true;
        if(y2 == 1) return false;

        if(x1 != x2) return x1 < x2;
        return y1 > y2;
    });

    p.erase(unique(p.begin(),p.end()), p.end());

    cout << p.size() << '\n';
    for(auto [x,y] : p) cout << x << ' ' << y << '\n';
}