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

        int ans = INT_MAX;

        for(int x = 0; x <= 2; x++) {
            for(int y = 0; y <= 1; y++) {
                for(int z = 0; z <= 5; z++) {
                    for(int k = 0; k <= 3; k++) {
                        int currN = x + 3*y + z*6 + k*10;
                        if(currN > n || (n-currN)%15 != 0) continue;
                        int w = (n-currN)/15;
                        ans = min(ans, x+y+z+k+w);
                    }
                }
            }
        }

        cout << ans << '\n';
    }
}