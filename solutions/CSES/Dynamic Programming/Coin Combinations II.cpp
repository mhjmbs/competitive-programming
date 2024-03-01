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

    int n, x;
    cin >> n >> x;

    int m = 1e9+7;

    vector<int> c(n);
    for(int& ci : c) cin >> ci;

    vector<ll> dp(x+1, 0);
    dp[0] = 1;

    for(int ci : c) {
        for(int i = 1; i <= x; i++) {
            if(i-ci >= 0) dp[i] = (dp[i] + dp[i-ci]) % m;
        }
    }

    cout << dp[x] << '\n';
}