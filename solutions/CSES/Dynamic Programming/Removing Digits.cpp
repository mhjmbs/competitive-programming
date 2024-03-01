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

vector<int> digits(int n) {
    vector<int> ans;
    while(n != 0) {
        ans.push_back(n%10);
        n/=10;
    }
    return ans;
}

int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> dp(n+1, INT_MAX-1);
    dp[n] = 0;

    for(int i = n; i >= 0; i--) {
        for(int d : digits(i)) {
            dp[i-d] = min(dp[i-d], dp[i]+1);
        }
    }

    cout << dp[0] << '\n';
}