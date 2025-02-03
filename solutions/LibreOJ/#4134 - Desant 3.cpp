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

int n, m;
vector<pii> queries;
string s;
vector<int> ans;

void solve() {
    vector<vector<int>> dp(n+1, vector<int>(3, 0));
    dp[0][0] = 1;

    for(int i = 0; i < n; i++) {
        vector<vector<int>> ndp(n+1, vector<int>(3, 0));
        for(int k = 0; k <= n; k++) {
            if(s[i] != '1') {
                ndp[k][0] = dp[k][0];
                ndp[k][2] = dp[k][1] ^ dp[k][2]; 
            }
            if(s[i] != '0') {
                if(k-1 >= 0) ndp[k][1] = dp[k-1][0] ^ dp[k-1][1];
            }
        }
        swap(dp, ndp);
    }

    for(int k = 0; k <= n; k++) {
        ans[k] ^= dp[k][1] ^ dp[k][2];
    }
}

void backtracking(int i) {
    if(i == m) {
        solve();
        return;
    }

    auto [a,b] = queries[i];

    if(s[a] == '1' || s[b] == '0') {
        swap(s[a],s[b]);
        backtracking(i+1);
        swap(s[a],s[b]);
    }else if(s[a] == '?' && s[b] == '?') {
        s[a] = s[b] = '0';
        backtracking(i+1);
        s[a] = s[b] = '1';
        backtracking(i+1);
        s[a] = s[b] = '?';
    }else {
        backtracking(i+1);
    }
}

int main() {
    fastio;

    cin >> n >> m;

    queries.resize(m);
    s.resize(n, '?');
    ans.resize(n+1);
    
    for(auto& [a,b] : queries) {
        cin >> a >> b;
        a--,b--;
    }

    backtracking(0);

    for(int k = 1; k <= n; k++) {
        cout << ans[k] << ' ';
    }
    cout << '\n';
}