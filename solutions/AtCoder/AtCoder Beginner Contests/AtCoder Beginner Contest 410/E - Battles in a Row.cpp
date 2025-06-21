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



int main() {
    fastio;

    int n, h, m;
    cin >> n >> h >> m;

    vector<int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(h+1, -1));
    dp[0][h] = m;

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        for(int hi = 0; hi <= h; hi++) {
            if(dp[i-1][hi] == -1) continue;
            if(hi-a[i] >= 0) {
                dp[i][hi-a[i]] = max(dp[i][hi-a[i]], dp[i-1][hi]);
                ans = i;
            }
            if(dp[i-1][hi]-b[i] >= 0) {
                dp[i][hi] = max(dp[i][hi], dp[i-1][hi] - b[i]);
                ans = i;
            }
        }
    }

    cout << ans << '\n';
}