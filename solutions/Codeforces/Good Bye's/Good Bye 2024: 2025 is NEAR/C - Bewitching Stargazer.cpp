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
    
    int t;
    cin >> t;
    
    while(t--) {
        ll n, k;
        cin >> n >> k;
        
        ll ans = 0, count = 1;
        double mid = (1+n)/2.0;
        
        while(n >= k) {
            if(n % 2 == 1) ans += ll(count*mid);
            n = (n%2 == 1) ? (n-1)/2 : n/2;
            count *= 2;
        }
        
        cout << ans << '\n';
    }
}