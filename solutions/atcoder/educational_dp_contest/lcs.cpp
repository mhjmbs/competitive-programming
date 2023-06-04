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

    string s, t;
    cin >> s >> t;

    vector<int> dp(t.size(), 0);
    vector<string> lcs(t.size(), "");
    int ans = 0, end = -1;

    for(int i = 0; i < s.size(); i++) {
        int best = 0, best_i = 0;
        for(int j = 0; j < t.size(); j++) {
            int next_best = best, next_best_i = best_i;
            if(dp[j] > best) {
                next_best = dp[j];
                next_best_i = j;
            }
            
            if(s[i] == t[j]) {
                if(dp[j] < best+1) {
                    dp[j] = best+1;
                    lcs[j] = lcs[best_i] + s[i];
                }

                if(dp[j] > ans) {
                    ans = dp[j];
                    end = j;
                }
            }
            best = next_best;
            best_i = next_best_i;
        }
    }

    cout << lcs[end] << '\n';
}