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

ll dp[int(1e6)+1][2];

int main() {
    fastio;

    int t;
    cin >> t;

    int m = 1e9+7;

    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i = 2; i <= int(1e6); i++) {
        dp[i][0] = (dp[i][0] + dp[i-1][1] + 2*dp[i-1][0]) % m;
        dp[i][1] = (dp[i][1] +dp[i-1][0] + 4*dp[i-1][1]) % m;
    }

    while(t--) {
        int n;
        cin >> n;

        cout << (dp[n][0] + dp[n][1]) % m << '\n';
    }
}