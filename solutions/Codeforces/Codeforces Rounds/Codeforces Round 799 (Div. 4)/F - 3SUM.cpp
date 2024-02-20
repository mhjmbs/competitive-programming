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



int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for(int& ai : a) {
            cin >> ai;
            ai %= 10;
        }

        bool yes = false;

        vector<vector<int>> dp(4, vector<int>(10, 0));
        dp[0][0] = 1;
        
        for(int ai : a) {
            auto oldDP = dp;
            for(int count = 1; count <= 3; count++) {
                for(int sum = 0; sum < 10; sum++) {
                    dp[count][sum] = oldDP[count][sum] || oldDP[count-1][(sum-ai+10) % 10];
                }
            }
        }

        cout << (dp[3][3] ? "YES\n" : "NO\n");
    }    
}