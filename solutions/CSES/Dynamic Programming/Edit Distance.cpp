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

    int n, m;
    string s1, s2;
    
    cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9+7));
    
    for(int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }

    for(int i = 0; i <= m; i++) {
        dp[0][i] = i;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = min({
                dp[i][j-1]+1,
                dp[i-1][j]+1,
                dp[i-1][j-1] + (s1[i-1] != s2[j-1])
            });
        }
    }

    cout << dp[n][m] << '\n';
}
