#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> h(n+1);
    for(int i = 1; i <= n; i++) cin >> h[i];

    vector<int> dp(n+1, INT_MAX);
    
    dp[1] = 0;

    for(int i = 2; i <= n; i++) {
        if(dp[i-1] != INT_MAX) dp[i] = min(dp[i], dp[i-1] + abs(h[i-1] - h[i]));
        if(dp[i-2] != INT_MAX) dp[i] = min(dp[i], dp[i-2] + abs(h[i-2] - h[i]));
    }

    cout << dp[n] << '\n';
}
