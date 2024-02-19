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

        vector<ll> a(n);
        for(ll& ai : a) cin >> ai;

        ll curr = 0;
        for(int i = 0; i < n; i++) {
            ll l = 1, r = 1e12, ans = -1;

            while(l <= r) {
                ll mid = (l+r)/2;

                if(a[i]*mid > curr) {
                    ans = mid;
                    r = mid-1;
                }else {
                    l = mid+1;
                }
            }

            curr = a[i]*ans;
        }

        cout << curr << '\n';
    }
}