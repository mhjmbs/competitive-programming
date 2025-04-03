#pragma GCC optimize ("O3")
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

vector<int> z_func(const string &s) {
    vector<int> z(s.size());
    z[0] = 0;

    for(int i = 1, l = 0, r = 0; i < s.size(); i++) {
        if(i < r) {
            z[i] = min(z[i-l], r-i);
        }
        while(i+z[i] < s.size() && s[i+z[i]] == s[z[i]]) {
            z[i]++;
        }
        if(i+z[i] > r) {
            l = i;
            r = i+z[i];
        }
    }

    z[0] = s.size();
    return z;
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(2, 1e9)));
    dp[0][0][0] = 0;
    dp[0][0][1] = 1;

    int ans = 1e9;

    for(int i = 0; i < n; i++) {
        vector<int> z = z_func((i == n ? "" : s.substr(i+1-1)) + "#" + t);
        z.erase(z.begin(), z.begin()+n-i+1);
        for(int j = 0; j <= m; j++) {
            if(i+1 <= n) dp[i+1][j][1] = min({dp[i+1][j][1], dp[i][j][0]+1, dp[i][j][1]});
            int sz = 1;

            for(int k = j+1; k <= m; k++) {
                while(z[k-1] >= sz) {
                    if(i == 0 && k != 1 || i+sz == n && k < m && z[m-sz] < sz) ans = min(ans, dp[i][j][1]+sz);
                    dp[i+sz][k+sz-1][0] = min(dp[i+sz][k+sz-1][0], dp[i][j][1]+sz);
                    if(i == 0) dp[i+sz][k+sz-1][0] = min(dp[i+sz][k+sz-1][0], dp[i][j][0]+sz);
                    sz++;
                }
            }

            if(i+sz <= n) {
                if(i == 0) ans = min(ans, dp[i][j][0]+sz + (i+sz != n));
                else ans = min(ans, dp[i][j][1]+sz + (i+sz != n));
            }
        }
    }

    ans = min(ans, n);

    cout << ans << '\n';
}