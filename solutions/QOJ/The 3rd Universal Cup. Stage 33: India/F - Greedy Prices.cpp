#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll apply(pll f, ll x) {
    return f.first*x + f.second;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n, q;
        cin >> n >> q;

        vector<ll> a(n), b(n);
        for(ll& ai : a) cin >> ai;
        for(ll& bi : b) cin >> bi;

        vector<pll> f;
        vector<ll> m0 = {0};
        ll offset = 0;
        for(int i = 0; i < n; i++) {
            if(b[i] == 0) offset++;
            else if(a[i] == 0) m0.push_back(b[i]);
            else f.emplace_back(a[i],b[i]);
        }

        n = f.size();

        sort(f.begin(), f.end(), [](pll f1, pll f2) {
            auto [a1, b1] = f1;
            auto [a2, b2] = f2;
            return a2*b1 < a1*b2;
        });
        
        sort(m0.begin(), m0.end());
        for(int i = 1; i < m0.size(); i++) {
            m0[i] += m0[i-1];
        }

        vector<vector<ll>> dp(n+1, vector<ll>(31, 1e9+1));
        dp[0][0] = 0;

        for(int i = 1; i <= n; i++) {
            for(int k = 0; k <= 30; k++) {
                dp[i][k] = dp[i-1][k];
                if(k > 0 && ll(1e9)/f[i-1].first >= dp[i-1][k-1]) {
                    dp[i][k] = min(dp[i][k], dp[i-1][k-1] + apply(f[i-1], dp[i-1][k-1]));
                }
            }
        }

        while(q--) {
            int p;
            cin >> p;

            ll ans = -1;

            for(int k = 0; k <= 30; k++) {
                if(dp[n][k] > p) continue;
                int m0_count = upper_bound(m0.begin(), m0.end(), p - dp[n][k]) - m0.begin() - 1;
                ans = max(ans, offset + k + m0_count);
            }

            cout << ans << ' ';
        }
        cout << '\n';
    }
}