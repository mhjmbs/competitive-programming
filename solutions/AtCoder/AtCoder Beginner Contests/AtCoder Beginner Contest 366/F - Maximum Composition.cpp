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

    ll n, k;
    cin >> n >> k;

    vector<pll> f(n+1);
    for(int i = 1; i <= n; i++) {
        auto& [a,b] = f[i];
        cin >> a >> b;
    }

    auto comp = [](pii f1, pii f2) {
        return (f1.first - 1)*f2.second < (f2.first - 1)*f1.second;
    };

    sort(f.begin()+1, f.end(), comp);

    vector<vector<ll>> dp(k+1, vector<ll>(n+1,1));

    for(int h = 1; h <= k; h++) {
        for(int i = 1; i <= n; i++) {
            auto [a,b] = f[i];
            dp[h][i] = max(dp[h][i-1], a*dp[h-1][i-1]+b);
        }
    }

    cout << dp[k][n] << '\n';
}