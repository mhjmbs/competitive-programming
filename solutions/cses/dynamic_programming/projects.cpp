#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using tiii = tuple<int,int,int>;

int main() {
    fastio;

    int n;
    cin >> n;

    vector<tiii> projects(n);

    for(int i = 0; i < n; i++) cin >> get<0>(projects[i]) >> get<1>(projects[i]) >> get<2>(projects[i]);

    auto comp = [](tiii a, tiii b) {
        return get<1>(a) < get<1>(b);
    };

    sort(projects.begin(), projects.end(), comp);

    map<int,ll> dp;
    ll ans = 0;

    for(int i = 0; i < n; i++) {
        auto [cs, ce, cp] = projects[i];

        auto it = dp.lower_bound(cs);
        if(it != dp.begin()) it--;

        if(it != dp.end() && it->first < cs) {
            dp[ce] = max(ans, it->second + cp);
            ans = max(ans, dp[ce]);
        }else {
            dp[ce] = max(ans, ll(cp));
            ans = max(ans, dp[ce]);
        }
    }

    cout << ans << '\n';
}