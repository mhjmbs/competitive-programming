#pragma once
#include <tuple>
#include <cstdlib>

namespace cp {

using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
    a = abs(a);
    b = abs(b);
    while(b > 0) {
        tie(a,b) = make_tuple(b, a % b);
    }
    return a;
}

}