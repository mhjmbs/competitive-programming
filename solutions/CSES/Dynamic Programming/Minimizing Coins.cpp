#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n, x;
    cin >> n >> x;

    vector<int> coin(n);

    for(int& c : coin) cin >> c;
    
    vector<int> dp(x+1, int(1e8));
    dp[0] = 0;

    for(int i = 1; i <= x; i++) {
        for(int c : coin) {
            if(i-c >= 0) {
                dp[i] = min(dp[i], dp[i-c] + 1);
            }
        }
    }
    
    if(dp[x] != int(1e8)) {
        cout << dp[x] << '\n';
    }else {
        cout << "-1\n";
    }
}
