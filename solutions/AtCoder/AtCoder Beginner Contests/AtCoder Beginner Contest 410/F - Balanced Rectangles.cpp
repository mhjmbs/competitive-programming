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

    int t;
    cin >> t;

    while(t--) {
        int h, w;
        cin >> h >> w;

        vector<string> grid;

        if(h <= w) {
            grid.resize(h);
            for(string& line : grid) cin >> line;
        }else {
            swap(h, w);
            grid.resize(h, string(w, ' '));
            for(int j = 0; j < w; j++) {
                for(int i = 0; i < h; i++) {
                    cin >> grid[i][j];
                }
            }
        }

        vector<int> occur(2*(h*w)+1);
        occur[0+(h*w)] = 1;
        ll ans = 0;
        
        for(int u = 0; u < h; u++) {
            vector<int> c(w), pref(w+1);
            for(int d = u; d < h; d++) {
                for(int j = 0; j < w; j++) {
                    c[j] += (grid[d][j] == '.') ? 1 : -1;
                    pref[j+1] = pref[j] + c[j];
                    ans += occur[pref[j+1]+(h*w)];
                    occur[pref[j+1]+(h*w)]++;
                }
                for(int j = 0; j < w; j++) occur[pref[j+1]+(h*w)]--;
            }
        }

        cout << ans << '\n';
    }
}