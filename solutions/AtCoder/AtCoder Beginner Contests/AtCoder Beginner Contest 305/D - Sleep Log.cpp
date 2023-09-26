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

    int n;
    cin >> n;

    vector<int> a(n+1);

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<ll> prefix(n+1,0);

    for(int i = 2; i <= n; i++) {
        if(i%2 == 0) {
            prefix[i] = prefix[i-1];
        }else {
            prefix[i] = prefix[i-1] + a[i]-a[i-1];
        }
    }

    int q;
    cin >> q;

    while(q--) {
        int l, r;
        cin >> l >> r;

        int i_l = lower_bound(a.begin()+1, a.end(), l) - (a.begin());
        int i_r = lower_bound(a.begin()+1, a.end(), r) - (a.begin());

        int prefix_l = prefix[i_l];

        if(i_l % 2 == 1) {
            prefix_l -= a[i_l] - l;
        }

        int prefix_r = prefix[i_r];
        
        if(i_r % 2 == 1) {
            prefix_r -= a[i_r] - r;
        }

        cout << prefix_r - prefix_l << '\n';
    }
}