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

int dfs(int u, string& s, vector<int>& dp) {
    if(dp[u] != -1) return dp[u];

    dp[u] = 0;

    if(s[u] == '<') {
        return dp[u] = (u == 0) ? 1 : dfs(u-1, s, dp)+1;
    }else if(s[u] == '>'){
        return dp[u] = (u == s.size()-1) ? 1 : dfs(u+1, s, dp)+1;
    }else {
        return dp[u] = max((u == 0) ? 1 : dfs(u-1, s, dp)+1, (u == s.size()-1) ? 1 : dfs(u+1, s, dp)+1);
    }
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        int n = s.size();

        int ans = 0;

        for(int i = 0; i < n-1; i++) {
            if((s[i] == '>' || s[i] == '*') && (s[i+1] == '*' || s[i+1] == '<')) {
                ans = 1e9;
            }
        }

        vector<int> vis(n), dp(n,-1);

        for(int i = 0; i < n; i++) {
            if(dp[i] == -1) {
                ans = max(ans, dfs(i, s, dp));
            }
        }


        cout << (ans == 1e9 ? -1 : ans) << '\n';
    }
    
}