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



int main() {
    fastio;

    int n;
    cin >> n;

    int m = 1e9+7;

    vector<string> grid(n);
    for(string& line : grid) cin >> line;

    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    if(grid[0][0] == '.') dp[0][0] = 1;

    auto inbounds = [n, &grid](int i, int j) {
        return 0 <= i && i < n && 0 <= j && j < n && grid[i][j] == '.';
    };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] != '.') continue;
            if(inbounds(i-1,j)) dp[i][j] = (dp[i][j] + dp[i-1][j]) % m;
            if(inbounds(i,j-1)) dp[i][j] = (dp[i][j] + dp[i][j-1]) % m;
        }
    }

    cout << dp[n-1][n-1] << '\n';
}