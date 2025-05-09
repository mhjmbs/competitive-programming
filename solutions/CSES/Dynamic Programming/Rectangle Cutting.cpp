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

    int a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a+1, vector<int>(b+1, 1e9));

    for(int i = 0; i <= a; i++) {
        for(int j = 0; j <= b; j++) {
            if(i == j) {
                dp[i][j] = 0;
                continue;
            } 
        
            for(int k = 1; k < i; k++) {
               dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1); 
            }
            
            for(int k = 1; k < j; k++) {
               dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1); 
            }
        }
    }

    cout << dp[a][b] << '\n';
}
