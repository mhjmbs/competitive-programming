#pragma once

#include <bits/stdc++.h>

using namespace std;

template <typename T>
vector<T> sieve(int n) {
    vector<T> is_p(n+1, true);
    is_p[0] = is_p[1] = false;
    
    for(T i = 2; i*i <= n; i++) {
        if(is_p[i]) {
            for(T j = i*i; j <= n; j+=i) {
                is_p[j] = false;
            }
        }
    }

    return is_p;
}