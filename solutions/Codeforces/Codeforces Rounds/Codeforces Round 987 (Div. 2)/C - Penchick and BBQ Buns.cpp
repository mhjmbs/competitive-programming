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

        vector<int> ans(n);

        if(n%2 == 0) {
            for(int i = 0, curr = 1; i < n-1; i+=2, curr++) {
                ans[i] = ans[i+1] = curr;
            }
        }else if(n >= 27){
            ans[0] = ans[9] = ans[25] = 1;
            ans[22] = ans[26] = 2;
            for(int i = 0, curr = 3; i < n-1; i++) {
                if(ans[i] != 0) continue;
                ans[i] = ans[i+1] = curr;
                curr++;
                i++;
            }
        }else {
            cout << "-1\n";
            continue;
        }

        for(int ai : ans) cout << ai << ' ';
        cout << '\n';
    }
}