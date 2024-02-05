#pragma once

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

namespace cp {

ll binExp(ll a, ll b, ll m = LONG_LONG_MAX) {
    a %= m;
    ll ans = 1;
    while(b > 0) {
        if(b&1) ans = (ans * a) % m;
        b >>= 1;
        a = (a*a) % m;
    }
    return ans;
}

}