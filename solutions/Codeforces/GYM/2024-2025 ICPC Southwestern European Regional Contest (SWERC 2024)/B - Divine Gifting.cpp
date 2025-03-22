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

    int n, k;
    cin >> n >> k;

    vector<pll> d(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> d[i].first;
        d[i].second = i;
    }
    sort(d.begin()+1, d.end());

    vector<vector<ll>> p(n+1, vector<ll>(n+1, 0));

    for(int len = 2; len <= n; len++) {
        for(int i = 1; i + len <= n+1; i++) {
            p[i][i+len-1] = p[i+1][i+len-1] + (d[i+len-1].first-d[i].first)*(d[i+len-1].first-d[i].first);
        }
    }

    vector<vector<ll>> dp(n+1, vector<ll>(k+1, 1e16));
    vector<vector<pll>> last(n+1, vector<pll>(k+1, {-1,-1}));

    dp[0][0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int ck = 1; ck <= k; ck++) {
            for(int l = 1; l <= i; l++) {
                ll curr = dp[l-1][ck-1] + p[l][i];
                if(curr < dp[i][ck]) {
                    dp[i][ck] = curr;
                    last[i][ck] = {l-1,ck-1};
                }
            }
        }
    }

    int best_k = min_element(dp[n].begin(), dp[n].end()) - dp[n].begin();

    int i = n, ck = best_k;

    vector<ll> ans(n+1);

    while(last[i][ck] != make_pair(-1ll,-1ll)) {
        for(int j = i; j > last[i][ck].first; j--) {
            ans[d[j].second] = d[i].first;
        }
        tie(i,ck) = last[i][ck];
    };

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}