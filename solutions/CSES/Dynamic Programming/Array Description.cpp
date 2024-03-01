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



int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    int M = 1e9+7;

    vector<int> x(n);
    for(int& xi : x) cin >> xi;

    vector<ll> dp(m+2, 0);
    if(x[0] != 0) dp[x[0]] = 1;
    else fill(dp.begin()+1, dp.end()-1, 1);

    for(int i = 1; i < n; i++) {
        vector<ll> ndp(m+2, 0);
        if(x[i] == 0) {
            for(int num = 1; num <= m; num++) {
                ndp[num] = (dp[num-1] + dp[num] + dp[num+1]) % M;
            }
        }else {
            ndp[x[i]] = (dp[x[i]-1] + dp[x[i]] + dp[x[i]+1]) % M;
        }
        swap(dp, ndp);
    }

    cout << accumulate(dp.begin(), dp.end(), 0LL) % M << '\n';
}