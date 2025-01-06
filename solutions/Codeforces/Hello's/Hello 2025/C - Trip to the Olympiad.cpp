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

int f(int a, int b, int c) {
    return (a^b) + (a^c) + (b^c);
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int l, r;
        cin >> l >> r;

        int m1 = 0, m2 = 0;

        int i = __lg(r);

        while((l & (1<<i)) == (r & (1<<i))) {
            m1 = m2 |= l & (1<<i);
            i--;
        }

        m1 |= (1<<i);
        i--;

        bool ok1 = false, ok2 = false;

        while(i >= 0) {
            if(r & (1<<i)) ok1 = true;
            else if(!(l & (1<<i)) && ok1) m1 |= (1<<i);

            if(!(l & (1<<i))) {
                ok2 = true;
                m2 |= (1<<i);
            }else if((l & (1<<i)) && !ok2) {
                m2 |= (1<<i);
            }

            i--;
        }

        int ans;

        if((l < m1 && m1 < r) && (l < m2 && m2 < r)) {
            ans = (f(l,m1,r) > f(l,m2,r)) ? m1 : m2;
        }else if(l < m1 && m1 < r) {
            ans = m1;
        }else {
            ans = m2;
        }

        cout << l << ' ' << ans << ' ' << r << '\n';
    }
}