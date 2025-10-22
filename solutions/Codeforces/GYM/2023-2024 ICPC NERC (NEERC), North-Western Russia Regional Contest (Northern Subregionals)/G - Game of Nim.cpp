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

    int n, p, m;
    cin >> n >> p >> m;

    vector<vector<int>> dp(n+1, vector<int>(1<<10));
    dp[n-p][p] = 1;

    for(int np = 1; np <= n; np++) {
        for(int rem = n-p-1; rem >= 0; rem--) {
            if(rem+np > n) continue;
            for(int x = 0; x < (1<<10); x++) {
                dp[rem][x] = (dp[rem][x] + dp[rem+np][x^np]) % m;
            }
        }
    }

    cout << dp[0][0] << '\n';
}