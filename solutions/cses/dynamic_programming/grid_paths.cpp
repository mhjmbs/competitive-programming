#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<string> grid(n);

    for(string& s : grid) {
        cin >> s;
    }

    vector<vector<int>> dp(n, vector<int>(n,0));
    
    if(grid[0][0] != '*') {
        dp[0][0] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '*') continue;
            if(j-1 >= 0) {
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= int(1e9) + 7;
            }
            if(i-1 >= 0) {
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= int(1e9) + 7;
            }
        }
    }

    cout << dp[n-1][n-1] << '\n';
}
