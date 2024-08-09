#pragma once

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

namespace cp {

ll gcd(ll a, ll b) {
    a = abs(a);
    b = abs(b);
    while(b > 0) {
        tie(a,b) = make_tuple(b, a % b);
    }
    return a;
}

}