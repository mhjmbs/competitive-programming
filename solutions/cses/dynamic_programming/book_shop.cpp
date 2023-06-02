#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n, x;
    cin >> n >> x;

    vector<int> price(n+1), pages(n+1);

    for(int b = 1; b < n+1; b++) cin >> price[b];
    for(int b = 1; b < n+1; b++) cin >> pages[b];

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    for(int b = 1; b <= n; b++) {
        for(int s = 1; s <= x; s++) {
            dp[b][s] = dp[b-1][s];

            if(s-price[b] >= 0) {
                dp[b][s] = max(dp[b][s], dp[b-1][s-price[b]] + pages[b]);
            }
        }
    }

    cout << dp[n][x] << '\n';
}
