#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;



int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> lastOccur(26, -1);
        vector<ll> dp(n+1, 0);
        for(int i = n-1; i >= 0; i--) {
            if(lastOccur[s[i]-'a'] == -1) dp[i] = dp[i+1] + n-i;
            else dp[i] = dp[i+1] + lastOccur[s[i]-'a'] - i; 
            lastOccur[s[i]-'a'] = i;
        }

        cout << dp[0] << '\n';
    }
}