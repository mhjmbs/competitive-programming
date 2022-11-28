#include "bits/stdc++.h"
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    int n, x;
 
    cin >> n >> x;
 
    vector<int> coin(n+1);
 
    for(int i = 1; i < n+1; i++) cin >> coin[i];
 
    sort(coin.begin(), coin.end());
 
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
 
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
 
    for(int c = 1; c <= n; c++) {
        for(int s = 1; s <= x; s++) {
            dp[c][s] = dp[c-1][s];
 
            if(s-coin[c] >= 0) {
                dp[c][s] += dp[c][s-coin[c]];
                dp[c][s] %= int(1e9) + 7;
            }
        }
    }
 
    cout << dp[n][x] << '\n';
}
