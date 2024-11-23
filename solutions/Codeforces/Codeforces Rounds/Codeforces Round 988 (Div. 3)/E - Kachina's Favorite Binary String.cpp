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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll query(int l, int r) {
    l++,r++;
    cout << "? " << l << ' ' << r << endl;
    ll ans;
    cin >> ans;
    return ans;
}

int solve() {
    int n;
    cin >> n;

    ll all = query(0,n-1);

    if(all == 0) {
        cout << "! IMPOSSIBLE" << endl;
        return 0;
    }

    string ans(n, '-');

    int l = 0, r = n-1;
    ll last_add;

    while(true) {
        if(l+1 == r) {
            ans[l] = '0';
            ans[r] = '1';
            cout << "! " << ans << endl;
            return 0;
        }

        ll curr = query(l+1, r);
        if(curr == all) {
            ans[l] = '1';
        }else {
            ans[l] = '0';
            break;
        }
        l++;
    }

    while(true) {
        if(l+1 == r) {
            ans[r] = '1';
            cout << "! " << ans << endl;
            return 0;
        }

        ll curr = query(l, r-1);
        last_add = curr;
        if(curr == all) {
            ans[r] = '0';
        }else {
            ans[r] = '1';
            break;
        }
        r--;
    }

    int r2 = l+1;
    ll curr, last = 0;

    while(r2+1 < r) { 
        curr = query(l,r2);
        if(curr == last) ans[r2] = '0';
        else ans[r2] = '1';
        last = curr;

        r2++;
    }

    if(last == last_add) ans[r2] = '0';
    else ans[r2] = '1';

    cout << "! " << ans << endl;

    return 0;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}