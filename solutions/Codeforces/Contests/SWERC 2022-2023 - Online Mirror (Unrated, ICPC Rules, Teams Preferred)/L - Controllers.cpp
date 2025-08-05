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



int main() {
    fastio;

    int n;
    cin >> n;

    string s;
    cin >> s;

    int p = count(s.begin(), s.end(), '+');
    int m = n-p;
    if(p < m) swap(p,m);

    int q;
    cin >> q;

    while(q--) {
        ll a, b;
        cin >> a >> b;
        if(a < b) swap(a,b);
        
        ll l = lcm(a,b);
        ll ca = l/a, cb = l/b;

        if(cb == ca) {
            cout << (p == m ? "YES\n" : "NO\n");
        }else {
            cout << ((p-m) % (cb-ca) == 0 && cb*(p-m)/(cb-ca) <= p && ca*(p-m)/(cb-ca) <= m ? "YES\n" : "NO\n");
        }
    }
}