#include "bits/stdc++.h"
 
#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)
 
using namespace std;
using ll = long long;
using pii = pair<int,int>;
 
int main() {
    fastio;
 
    int n;
    cin >> n;
 
    if((n*(n+1))/2 % 2 == 0) {
        vector<vector<int>> dp(n*(n+1)/4+1, vector<int>(n+1, 0));
        dp[0] = vector<int>(n, 1);
 
        for(int i = 1; i <= n*(n+1)/4; i++) {
            for(int c = 1; c <= n; c++) {
                dp[i][c] = dp[i][c-1];
                if(i-c >= 0) dp[i][c] = (dp[i][c] + dp[i-c][c-1]) % (int(1e9)+7);
            }
        }
 
        cout << (dp[n*(n+1)/4][n] * 500000004ll) % (int(1e9)+7) << '\n';
    }else {
        cout << 0 << '\n';
    }
}