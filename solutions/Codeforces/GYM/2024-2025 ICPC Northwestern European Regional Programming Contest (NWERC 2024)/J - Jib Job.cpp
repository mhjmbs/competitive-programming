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

struct Crane {
    int x;
    int y;
    int h;
};

int dist(Crane a, Crane b) {
    return sqrt(abs(a.x-b.x)*abs(a.x-b.x) + abs(a.y-b.y)*abs(a.y-b.y));
}

int main() {
    fastio;

    int n;
    cin >> n;

    vector<Crane> a(n);
    for(auto& [x,y,h] : a) cin >> x >> y >> h;

    vector<int> ans(n);
    for(int i = 0; i < n; i++) ans[i] = a[i].h;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(a[i].h <= a[j].h) ans[i] = min(ans[i], dist(a[i],a[j]));
        }
    }

    for(int ans_i : ans) cout << ans_i << '\n';
}