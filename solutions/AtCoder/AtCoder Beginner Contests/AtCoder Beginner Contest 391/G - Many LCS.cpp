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

const int mod = 998244353;

int add(int a, int b) {
    return (a+b < mod) ? a+b : a+b-mod;
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<map<vector<int>,int>> dp(m+1);

    dp[0][vector<int>(n+1,0)] = 1;

    for(int sz = 1; sz <= m; sz++) {
        for(auto& [ldp,la] : dp[sz-1]) {
            for(char c = 'a'; c <= 'z'; c++) {
                vector<int> ndp = ldp;
                for(int i = 1; i <= n; i++) {
                    if(c == s[i-1]) {
                        ndp[i] = ldp[i-1]+1;
                    }else {
                        ndp[i] = max(ldp[i], ndp[i-1]);
                    }
                }
                dp[sz][ndp] = add(dp[sz][ndp],la);
            }
        }
    }

    vector<int> ans(n+1, 0);

    for(auto& [v,curr] : dp[m]) {
        ans[v[n]] = add(ans[v[n]], curr);
    }

    for(int i = 0; i <= n; i++) {
        cout << ans[i] << (i != n ? ' ' : '\n');
    }
}
