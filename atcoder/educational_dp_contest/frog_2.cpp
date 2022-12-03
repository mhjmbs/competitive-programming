#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<int> h(n+1);
    for(int i = 1; i <= n; i++) cin >> h[i];

    vector<int> dp(n+1, INT_MAX);

    dp[1] = 0;

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(i-j >= 1) {
                dp[i] = min(dp[i], dp[i-j] + abs(h[i-j] - h[i]));
            }
        }
    }

    cout << dp[n] << '\n';
}
