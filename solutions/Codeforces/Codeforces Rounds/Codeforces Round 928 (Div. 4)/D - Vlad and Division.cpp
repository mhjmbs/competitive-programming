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

        int ans = 0;
        multiset<unsigned int> occur;

        for(int i = 0; i < n; i++) {
            unsigned int ai;
            cin >> ai;

            if(occur.count(ai) > 0 || occur.count(ai ^ (1<<31)) > 0) {
                occur.erase(occur.lower_bound(ai));
                occur.erase(occur.lower_bound(ai ^ (1<<31)));
            }else {
                occur.insert(~ai);
                occur.insert(~ai ^ (1<<31));
                ans++;
            }
        }

        cout << ans << '\n';
    }
}