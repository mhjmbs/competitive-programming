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

        vector<vector<int>> dp(s.size()+1, vector<int>(2, 1e8));

        ll ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j <= n; j++) {
                int curr = 0;
                for(int k = i; k < j;) {
                    if(s[k] == '0') k++;
                    else {
                        curr++;
                        k += 3;
                    }
                }

                ans += curr;
            }
        }

        cout << ans << '\n';
    }
}