#pragma once
#include <tuple>
#include <cstdlib>


namespace cp {

using namespace std;

using ll = long long;
using tlll = tuple<ll,ll,ll>;

tlll pos_egcd(ll a, ll b) {
    if(b == 0) {
        return {a, 1, 0};
    }else {
        auto [gcd, x, y] = pos_egcd(b, a%b);
        return {gcd, y, x-(a/b)*y};
    }
}

tlll egcd(ll a, ll b) {
    auto [gcd, x, y] = pos_egcd(abs(a), abs(b));
    x = (a >= 0) ? x : -x;
    y = (b >= 0) ? y : -y;
    return {gcd, x, y};
}

}