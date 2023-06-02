#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    string n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n.size()+1, vector<int>(m.size()+1));

    for(int i = 0; i <= n.size(); i++) dp[i][0] = i;
    for(int i = 0; i <= m.size(); i++) dp[0][i] = i;

    for(int i = 1; i <= n.size(); i++) {
        for(int j = 1; j <= m.size(); j++) {
            dp[i][j] = min({dp[i][j-1]+1, dp[i-1][j]+1, dp[i-1][j-1] + (n[i-1] != m[j-1])});
        }
    }

    cout << dp[n.size()][m.size()] << '\n';
}