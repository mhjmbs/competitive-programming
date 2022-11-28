#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    
    int n, x;
    cin >> n >> x;

    vector<int> coin(n), dp(x+1, 0);
    for(int& c : coin) cin >> c;

    dp[0] = 1;

    for(int i = 1; i <= x; i++) {
        for(int c : coin) {
            if(i-c >= 0) {
                dp[i] += dp[i-c];
                dp[i] %= int(1e9) + 7;
            }
        }
    }

    cout << dp[x] << '\n';
}
