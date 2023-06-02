#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int a, b;
    cin >> a >> b;

    int ans = 0;
    vector<vector<int>> dp(501, vector<int>(501, INT_MAX));

    for(int i = 1; i <= 500; i++) dp[i][i] = 0;

    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= b; j++) {
            for(int cut = 1; cut < i; cut++) dp[i][j] = min(dp[i][j], dp[cut][j] + dp[i-cut][j] + 1);
            for(int cut = 1; cut < j; cut++) dp[i][j] = min(dp[i][j], dp[i][cut] + dp[i][j-cut] + 1);
        }
    }

    cout << dp[a][b] << '\n';
}