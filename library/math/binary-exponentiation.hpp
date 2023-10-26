#pragma once

namespace cp {

using ull = unsigned long long;

ull binary_exponentiation(ull a, ull b, const ull m) {
    a %= m;
    ull ans = 1;
    while(b > 0) {
        if(b&1) {
            ans = (ans * a) % m;
        }
        b >>= 1;
        a = (a*a) % m;
    }
    return ans;
}

}