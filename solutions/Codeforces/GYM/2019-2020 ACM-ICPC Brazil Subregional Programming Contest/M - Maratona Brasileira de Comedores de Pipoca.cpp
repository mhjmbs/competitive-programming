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

int n, c, t;
vector<int> p;

bool check(ll m) {
    ll sum = 0, comp = 1;

    for(int i = 0; i < p.size(); i++) {
        if(p[i] > m) return false;

        if(sum + p[i] > m) {
            sum = p[i];
            comp++;
        }else {
            sum += p[i];
        }
    }

    return comp <= c;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    cin >> n >> c >> t;

    p.resize(n);
    for(int &pi : p) cin >> pi;

    ll l = 1, r = 1e9, ans = -1;

    while(l <= r) {
        ll m = (l+r)/2;

        if(check(m)) {
            ans = m;
            r = m-1;
        }else {
            l = m +1;
        }
    }

    if(ans % t == 0) {
        cout << ans/t << '\n';
    }else {
        cout << ans/t+1 << '\n';
    }

    return 0;
}