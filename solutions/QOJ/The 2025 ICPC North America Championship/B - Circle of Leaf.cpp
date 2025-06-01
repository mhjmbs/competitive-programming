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

ll m = 998244353;

vector<vector<int>> g;
vector<vector<ll>> dp;

void dfs(int u, int p) {
    if(g[u].size() == 1) dp[u][0] = 1;

    vector<ll> pref(g[u].size()+2, 1), suff(g[u].size()+2, 1);

    for(int v : g[u]) {
        if(v == p) continue;
        dfs(v, u);
        dp[u][1] = dp[u][1] * (dp[v][1]+dp[v][0]) % m;
    }

    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(v == p) pref[i+1] = pref[i];
        else pref[i+1] = (dp[v][1]+dp[v][0]) * pref[i] % m;
    }

    for(int i = g[u].size()-1; i >= 0; i--) {
        int v = g[u][i];
        if(v == p) suff[i+1] = suff[i+2];
        else suff[i+1] = (dp[v][1]+dp[v][0]) * suff[i+2] % m;
    }

    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(v == p) continue;
        dp[u][0] = ( dp[u][0] + (dp[v][0] * pref[i] % m) * suff[i+2] ) % m;
    }
}

int main() {
    fastio;

    int n;
    cin >> n;

    g.resize(n+1);

    for(int m = 0; m < n-1; m++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dp.resize(n+1, {0,1});

    dfs(1, 0);

    cout << dp[1][1] << '\n';
}