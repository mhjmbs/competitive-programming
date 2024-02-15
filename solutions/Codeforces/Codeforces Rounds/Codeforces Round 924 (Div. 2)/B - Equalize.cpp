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

        vector<int> a(n);
        for(int& ai : a) cin >> ai;

        sort(a.begin(), a.end());
        int last = unique(a.begin(),a.end()) - a.begin();

        int l = 0, r = 0;
        int ans = 1;
        for(int i = 1; i < last; i++) {
            if(a[i] - a[l] <= n-1) {
                r = i;
                ans = max(ans, r-l+1);
            }else {
                while(a[i] - a[l] > n-1) l++;
            }
        }

        cout << ans << '\n';
    }
}