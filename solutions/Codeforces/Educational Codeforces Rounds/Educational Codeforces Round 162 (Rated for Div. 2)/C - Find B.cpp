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
        int n, q;
        cin >> n >> q;

        vector<int> c(n+1);
        for(int i = 1; i <= n; i++) cin >> c[i];

        vector<ll> pref(n+1, 0), oneCount(n+1, 0);
        for(int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + c[i];
            oneCount[i] = oneCount[i-1] + (c[i] == 1);
        }

        while(q--) {
            int l, r;
            cin >> l >> r;
            int ones = oneCount[r] - oneCount[l-1];
            if(l != r && pref[r]-pref[l-1] - ones - (r-l+1-ones) >= ones) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}