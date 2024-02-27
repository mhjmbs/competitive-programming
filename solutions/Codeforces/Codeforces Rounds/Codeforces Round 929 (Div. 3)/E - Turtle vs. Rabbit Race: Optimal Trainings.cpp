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

        vector<int> a(n+1);
        for(int i = 1; i <= n; i++) cin >> a[i];

        vector<ll> pref(n+1, 0);
        for(int i = 1; i <= n; i++) pref[i] = pref[i-1] + a[i];

        int q;
        cin >> q;

        while(q--) {
            int l, u;
            cin >> l >> u;

            int left = l, right = n, r = l;

            while(left <= right) {
                int mid = (left + right) / 2;

                if(pref[mid] - pref[l-1] <= u) {
                    r = mid;
                    left = mid+1;
                }else {
                    right = mid-1;
                }
            }

            if(r != n) {
                ll k = pref[r] - pref[l-1];
                ll ans1 = k*u - ((1+k-1)*(k-1)/2);
                k = pref[r+1] - pref[l-1];
                ll ans2 = k*u - ((1+k-1)*(k-1)/2);
            
                if(ans2 > ans1) r++;
            }

            cout << r << (q != 0 ? ' ' : '\n');
        }
    }
}