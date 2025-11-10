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
        int n;
        cin >> n;

        vector<vector<int>> a(2, vector<int>(n));
        for(auto& line : a) {
            for(int& aij : line) cin >> aij;
        }

        vector<vector<pii>> best(2, vector<pii>(n));

        best[0][0] = {a[0][0], a[0][0]};
        for(int i = 1; i < n; i++) {
            best[0][i] = {min(a[0][i],best[0][i-1].first), max(a[0][i],best[0][i-1].second)};
        }

        best[1][n-1] = {a[1][n-1],a[1][n-1]};
        for(int i = n-2; i >= 0; i--) {
            best[1][i] = {min(a[1][i],best[1][i+1].first), max(a[1][i],best[1][i+1].second)};
        }

        // for(int i = 0; i < 2; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << "(" << best[i][j].first << ' ' << best[i][j].second << ") ";
        //     }
        //     cout << '\n';
        // }

        vector<pii> paths(n);

        for(int i = 0; i < n; i++) {
            paths[i] = {
                min(best[0][i].first, best[1][i].first),
                max(best[0][i].second, best[1][i].second)
            };
        }

        sort(paths.begin(), paths.end());

        // for(auto[l,r] : paths) cout << "(" << l << "," << r << ") ";
        // cout << '\n';
        
        multiset<int> r;

        for(auto path : paths) r.insert(path.second);

        vector<int> min_r(2*n+1, 2*n+1);

        for(int i = 0, l = 1; i < n; i++) {
            while(l <= paths[i].first) {
                min_r[l] = *r.begin();
                l++;
            }
            r.erase(r.find(paths[i].second));
        }

        // for(int x : min_r) cout << x << ' ';
        // cout << '\n';
        
        ll ans = 0;
        for(int l = 1; l <= 2*n; l++) {
            ans += 2*n-min_r[l]+1;
        }
        
        cout << ans << '\n';
    }
}