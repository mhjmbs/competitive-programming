#pragma once
#include <algorithm>

using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
    while(b != 0) {
        tie(a,b) = make_tuple(b, a % b);
    }
    return a;
}