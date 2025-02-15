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

    int n;
    cin >> n;

    int x[5000];
    for(int i = 0; i < n; i++) cin >> x[i];


    ll dp[n][n][2];

    for(int i = 0; i < n; i++) {
        dp[i][i][0] = x[i];
        dp[i][i][1] = 0;
    }

    for(int sz = 2; sz <= n; sz++) {
        for(int l = 0, r = l+sz-1; r < n; l++, r = l+sz-1) {
            dp[l][r][0] = max(dp[l+1][r][1] + x[l], dp[l][r-1][1] + x[r]);  
            dp[l][r][1] = min(dp[l+1][r][0], dp[l][r-1][0]);  
        }
    }

    cout << dp[0][n-1][0] << '\n';
}
