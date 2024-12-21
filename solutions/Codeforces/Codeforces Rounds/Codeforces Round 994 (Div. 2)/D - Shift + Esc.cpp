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

int mod(int a, int m) {
    return (a % m + m) % m;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        ll n, m, k;
        cin >> n >> m >> k;

        vector<vector<ll>> a(n, vector<ll>(m));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(m, 1e16)));
        vector<vector<ll>> dpb(n, vector<ll>(m, 1e16));

        for(int s = 0; s < m; s++) {
            dp[0][0][s] = a[0][s];
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int s = 0; s < m; s++) {
                    if(i-1 >= 0) dp[i][j][s] = dpb[i-1][j] + a[i][mod(j+s,m)];
                    if(j-1 >= 0) dp[i][j][s] = min(dp[i][j][s], dp[i][j-1][s] + a[i][mod(j+s,m)]);
                    dpb[i][j] = min(dpb[i][j], k*s + dp[i][j][s]);
                }
            }
        }

        cout << dpb[n-1][m-1] << '\n';
    }
}