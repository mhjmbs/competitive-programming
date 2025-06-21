#include <bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

//using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
//using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<ll> fact(4e6+1,1);
ll m = 998244353;

ll bin_exp(ll a, ll b) {
    a %= m;
    ll ans = 1;
    while(b > 0) {
        if(b&1) ans = ans*a % m;
        a = a*a % m;
        b >>= 1;
    }
    return ans;
}

ll inv(ll n) {
    return bin_exp(n, m-2);
}

ll choose(ll a, ll b) {
    return fact[a]*inv(fact[a-b]*fact[b]) % m;
}

int main() {
    fastio;
    
    for(int i = 1; i < fact.size(); i++) fact[i] = fact[i-1]*i % m;
    
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    
    ll ans = 0;
    
    for(int i = a; i <= a+b+d; i++) {
        int lb = min(b, i-a);
        int rb = b-lb;
        int rd = d-(i-a-lb);
        
        ans = (ans + choose(a+lb, a) * choose(rb+c-1+rd, c-1)) % m;
        //cout << rb+c-1+rd << ' ' << ans << endl;
    }
    
    cout << ans << '\n';
}