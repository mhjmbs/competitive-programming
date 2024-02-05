#pragma once

#include <bits/stdc++.h>
#include "../math/binary-exponentiation.hpp"

using namespace std;

using ll = long long;

namespace cp {

template <ll p, ll m>
class Hash {
    int n;
    vector<ll> h;
    inline static vector<ll> pPow = {1};
    inline static vector<ll> invPow = {1};
    inline static ll invMod = binExp(p, m-2, m);
    
    public:

    Hash(const string& s) : n{s.size()}, h(s.size()+1, 0) {
        pPow.reserve(n);
        invPow.reserve(n);
        while(pPow.size() < n) pPow.push_back( mod(pPow.back()*p, m) );
        while(invPow.size() < n) invPow.push_back( mod(invPow.back()*invMod, m) );
        
        for(int i = 0; i < n; i++) {
            h[i+1] = mod(h[i] + (s[i] - 'a' + 1) * pPow[i], m);
        }
    }
    
    int substr(int l, int r) {
        return mod( mod(h[r+1] - h[l], m) * invPow[l], m);
    }
};

}