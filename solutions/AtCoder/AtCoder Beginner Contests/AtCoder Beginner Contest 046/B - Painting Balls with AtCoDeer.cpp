#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;



int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    vector<vector<ll>> dp(n, vector<ll>(k, 0));
    for(int i = 0; i < k; i++) dp[0][i] = 1;

    ll sumLast = k;
    for(int i = 1; i < n; i++) {
        ll newSumLast = 0;
        for(int j = 0; j < k; j++) {
            dp[i][j] = sumLast - dp[i-1][j];
            newSumLast += dp[i][j];
        }
        swap(sumLast, newSumLast);
    }

    ll ans = accumulate(dp[n-1].begin(), dp[n-1].end(), 0LL);

    cout << ans << '\n';
}