#include "bits/stdc++.h"
#define mod (int(1e9) + 7)

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int& ai : a) cin >> ai;

    vector<vector<int>> dp(n, vector<int>(m+1, 0));
    
    if(a[0] != 0) {
        dp[0][a[0]] = 1;
    }else {
        for(int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    }

    for(int s = 1; s < n; s++) {
        if(a[s] != 0) {
            dp[s][a[s]] = (dp[s][a[s]] + dp[s-1][a[s]-1]) % mod;
            dp[s][a[s]] = (dp[s][a[s]] + dp[s-1][a[s]]) % mod;
            if(a[s]+1 <= m) dp[s][a[s]] = (dp[s][a[s]] + dp[s-1][a[s]+1]) % mod;
        }else {
            for(int l = 1; l <= m; l++) {
                dp[s][l] = (dp[s][l] + dp[s-1][l-1]) % mod;
                dp[s][l] = (dp[s][l] + dp[s-1][l]) % mod;
                if(l+1 <= m) dp[s][l] = (dp[s][l] + dp[s-1][l+1]) % mod;
            }
        }
    }

    int ans = 0;
    
    for(int i = 1; i <= m; i++) ans = (ans + dp[n-1][i]) % mod;

    cout << ans << '\n';
}
