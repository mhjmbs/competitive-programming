#include "bits/stdc++.h"

using namespace std;

using ll = long long;

vector<ll> fact(61, 1);
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

ll inv(ll a) {
    return bin_exp(a, m-2);
}

ll choose(ll n, ll k) {
    if(k > n || k < 0) return 0;
    return fact[n]*inv(fact[n-k]*fact[k]) % m;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    for(int i = 1; i < fact.size(); i++) {
        fact[i] = fact[i-1]*i % m;
    }

    int t;
    cin >> t;
    
    while(t--) {
        ll n, k;
        cin >> n >> k;
        
        ll pref = 0, ans = 0;

        if(__popcount(n) == k) ans = (ans+n) % m;
        
        for(int i = 59; i >= 0; i--) {
            if(n & (1ll<<i)) {
                ans = (ans + (((1ll<<i)-1) % m)*choose(i-1, k-1)) % m;
                ans = (ans + pref*choose(i, k)) % m;
                k--;
                pref = (pref + (1ll<<i)) % m;
            }
        }
        
        cout << ans << '\n';
    }
}