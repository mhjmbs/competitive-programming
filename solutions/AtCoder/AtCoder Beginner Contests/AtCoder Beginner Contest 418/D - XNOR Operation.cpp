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

    int n;
    cin >> n;

    string s;
    cin >> s;

    ll ans = (s[0] == '1');
    
    vector<ll> dp(2);
    if(s[0] == '1') dp[1] = 1;
    else dp[0] = 1;

    for(int i = 1; i < n; i++) {
        vector<ll> ndp(2);
        ndp[0] = dp[!(s[i]-'0')] + (s[i] == '0');
        ndp[1] = dp[s[i]-'0'] + (s[i] == '1');
        ans += ndp[1];
        swap(dp, ndp);
    }

    cout << ans << '\n';
}