#pragma once

using ll = long long;

ll binary_exponentiation(ll a, ll b, ll m) {
    a %= m;
    ll ans = 1;
    while(b > 0) {
        if(b&1) {
            ans = (ans * a) % m;
        }
        b >>= 1;
        a = (a*a) % m;
    }
    return ans;
}