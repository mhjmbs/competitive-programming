#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main() {
    fastio;

    int t;
    cin >> t;

    vector<pll> dp(int(1e6)+1, {-1,-1});
    dp[1] = {1,1};

    int next = 2;

    while(t--) {
        int n;
        cin >> n;

        if(dp[n] != make_pair(-1ll,-1ll)) {
            cout << (dp[n].first + dp[n].second) % (ll(1e9)+7) << '\n';
            continue;
        }

        for(; next <= n; next++) {
            dp[next].first = (2*dp[next-1].first + dp[next-1].second) % (ll(1e9)+7);
            dp[next].second = (dp[next-1].first + 4*dp[next-1].second) % (ll(1e9)+7);
        }

        cout << (dp[n].first + dp[n].second) % (ll(1e9)+7) << '\n';
    }
}