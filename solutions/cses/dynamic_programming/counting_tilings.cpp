#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int n, m;
vector<vector<int>> dp, next_mask;

void generate_next_masks(int mask, int curr_next_mask, int i) {
    if(i > n) return;
    if(i == n) {
        next_mask[mask].push_back(curr_next_mask);
        return;
    }

    if((mask & (1<<i)) != 0) generate_next_masks(mask, curr_next_mask, i+1);
    if((mask & (1<<i)) == 0) generate_next_masks(mask, curr_next_mask ^ (1<<i), i+1);
    if((mask & (1<<i)) == 0 && (mask & (1<<(i+1))) == 0) generate_next_masks(mask, curr_next_mask, i+2);
}

int main() {
    fastio;

    cin >> n >> m;

    dp.resize(m+2, vector<int>(1<<n, 0));
    next_mask.resize(1<<n);

    for(int mask = 0; mask < 1<<n; mask++) generate_next_masks(mask, 0, 0);

    for(int next_mask : next_mask[0]) {
        dp[2][next_mask]++;
    }

    for(int i = 1; i <= m; i++) {
        for(int mask = 0; mask < 1<<n; mask++) {
            for(int next : next_mask[mask]) {
                dp[i+1][next] += dp[i][mask];
                dp[i+1][next] %= int(1e9) + 7;
            }
        }
    }

    cout << dp[m+1][0] << '\n'; 
}