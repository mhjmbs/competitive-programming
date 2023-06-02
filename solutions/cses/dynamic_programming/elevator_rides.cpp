#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int n, x;

int main() {
    fastio;

    cin >> n >> x;

    vector<int> w(n);
    for(int &wi : w) cin >> wi;

    vector<pll> dp(1<<n, {LONG_LONG_MAX,LONG_LONG_MAX});

    for(int i = 0; i < n; i++) dp[1<<i] = {0, w[i]};

    for(int comb = 0; comb < 1<<n; comb++) {
        for(int off = 0; off < n; off++) {
            if(comb & (1<<off) && (comb^(1<<off)) != 0) {
                pll new_ans = dp[comb^(1<<off)];
                if(new_ans.second + w[off] <= x) new_ans.second += w[off];
                else new_ans.first++, new_ans.second = w[off];
                dp[comb] = min(dp[comb], new_ans);
            }
        }
    }

    cout << dp[(1<<n)-1].first+1 << '\n';
}