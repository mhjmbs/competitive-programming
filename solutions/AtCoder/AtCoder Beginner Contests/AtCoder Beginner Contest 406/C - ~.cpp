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

    vector<int> p(n);
    for(int& pi : p) cin >> pi;

    ll i1 = 0, i2 = 1, i3 = 1, i4 = 1;
    ll ans = 0;

    while(i1 < n-1 && i2 < n-1 && i3 < n && i4 < n) {
        while(i1 < n-1 && p[i1] > p[i1+1]) {
            i1++;
        }
        
        while(i2 < n-1 && !(p[i2-1] < p[i2] && p[i2] > p[i2+1]) || i2 <= i1) {
            i2++;
        }
        
        while(i3 < n-1 && !(p[i3-1] > p[i3] && p[i3] < p[i3+1]) || i3 <= i2) {
            i3++;
        }
        
        while(i4 < n && p[i4-1] < p[i4] || i4 <= i3) {
            i4++;
        }
        
        if(i1 < n && i2 < n && i3 < n) ans += (i2-i1)*((i4-1)-i3);

        i1 = i3;
    }

    cout << ans << '\n';
}