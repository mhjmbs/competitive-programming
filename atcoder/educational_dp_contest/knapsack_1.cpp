#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);

    int n, w;
    cin >> n >> w;

    vector<int> weight(n+1, 0), value(n+1, 0);

    for(int i = 1; i <= n; i++) {
        cin >> weight[i];
        cin >> value[i];
    }

    vector<vector<ll>> dp(w+1, vector<ll>(n+1, 0));

    for(int i = 0; i <= n; i++) dp[0][i] = 0;

    for(int sw = 1; sw <= w; sw++) {
        for(int b = 1; b <= n; b++) {
            dp[sw][b] = dp[sw][b-1];

            if(sw - weight[b] >= 0) {
                dp[sw][b] = max(dp[sw][b], dp[sw - weight[b]][b-1] + value[b]);
            }
        }
    }

    cout << dp[w][n] << '\n';
}
