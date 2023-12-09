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

    while(t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int& ai : a) cin >> ai;

        vector<int> sA = a;
        sort(sA.begin(), sA.end());

        vector<int> dp(n, 0);
        dp[n-1] = n-1;

        vector<ll> pref(n+1, 0);
        for(int i = 1; i <= n; i++)
        {
            pref[i] = pref[i-1] + sA[i-1];
        }

        for(int i = n-2; i >= 0; i--)
        {
            if(pref[i+1] >= sA[i+1]) dp[i] = dp[i+1];
            else dp[i] = i;
        }

        for(int i = 0; i < n; i++)
        {
            cout << dp[lower_bound(sA.begin(), sA.end(), a[i]) - sA.begin()] << (i != n-1 ? ' ' : '\n');
        }
    }
}