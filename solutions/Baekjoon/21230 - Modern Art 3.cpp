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

    vector<int> v(n);
    for(int& vi : v) cin >> vi;

    vector<vector<int>> dp(n, vector<int>(n, 1e7));
    for(int i = 0; i < n; i++) dp[i][i] = 1;

    for(int sz = 2; sz <= n; sz++) {
        for(int l = 0; l+sz-1 < n; l++) {
            int r = l+sz-1;
            for(int k = l; k < r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k]+dp[k+1][r] - (v[l] == v[r]));
            }
        }
    }

    cout << dp[0][n-1] << '\n';
}