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
        int n, m;
        cin >> n >> m;

        multimap<int,int> wow;
        for(int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;
            wow.emplace(l,r);
        }


        int in = 0;
        multiset<int> exits;

        vector<int> dp(n+2, 0);
        for(int i = 1; i <= n; i++) {
            auto it = wow.lower_bound(i);
            while(it != wow.end() && it->first == i) {
                in++;
                exits.insert(it->second);
                wow.erase(it);
                it = wow.lower_bound(i);
            }

            dp[i+1] = max(dp[i+1], dp[i]);
            if(!exits.empty()) dp[*exits.rbegin()+1] = max(dp[*exits.rbegin()+1], dp[i]+in);

            while(!exits.empty() && *exits.begin() == i) {
                in--;
                exits.erase(exits.begin());
            }
        }

        cout << dp[n+1] << '\n';
    }
}