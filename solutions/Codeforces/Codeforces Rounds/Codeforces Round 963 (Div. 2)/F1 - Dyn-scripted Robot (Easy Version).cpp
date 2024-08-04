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

int MOD(ll x, ll m) {
    return (x%m + m) % m;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n, k, w, h;
        cin >> n >> k >> w >> h;

        string s;
        cin >> s;

        map<pll,int> count;

        ll x = 0, y = 0;

        for(char c : s) {
            if(c == 'L') x--;
            if(c == 'U') y++;
            if(c == 'R') x++;
            if(c == 'D') y--;

            x = MOD(x, 2*w);
            y = MOD(y, 2*h);
            count[{x,y}]++;
        }

        ll ans = 0;

        for(int i = 0; i < k; i++) {
            int x2 = MOD(-i*x, 2*w);
            int y2 = MOD(-i*y, 2*h);
            ans += count[{x2,y2}];
        }

        cout << ans << '\n';
    }
}