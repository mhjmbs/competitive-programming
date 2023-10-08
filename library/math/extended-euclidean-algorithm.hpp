#pragma once
#include <algorithm>

using namespace std;

using ll = long long;
using tlll = tuple<ll,ll,ll>;

tlll egcd(ll a, ll b) {
    if(b == 0) {
        return {a, 1, 0};
    }else {
        auto [gcd, x, y] = egcd(a, b);
        return {gcd, y, x-(a/b)*y};
    }
}