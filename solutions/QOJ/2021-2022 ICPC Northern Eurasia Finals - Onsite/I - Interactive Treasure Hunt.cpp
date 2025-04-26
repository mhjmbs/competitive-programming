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

int dig(int i, int j) {
    cout << "DIG " << i << ' ' << j << endl;
    int ans;
    cin >> ans;
    return ans;
}

int scan(int i, int j) {
    cout << "SCAN " << i << ' ' << j << endl;
    int ans;
    cin >> ans;
    return ans;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;
    
        ll a = scan(1,1);
        ll b = scan(1,m);

        ll sx = (a + 4 + b + 2*(1-m)) / 2;
        ll sy = (a + 4 - b - 2*(1-m)) / 2;

        ll c = scan(sx/2, 1);
        ll d = scan(1, sy/2);

        ll dx = c - sy + 2;
        ll dy = d - sx + 2;

        ll x1 = (sx - dx) / 2;
        ll x2 = (sx + dx) / 2;
        ll y1 = (sy - dy) / 2;
        ll y2 = (sy + dy) / 2;

        if(dig(x1,y1)) {
            dig(x2,y2);
        }else {
            dig(x1,y2);
            dig(x2,y1);
        }
    }
}