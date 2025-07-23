#pragma once

#include <bits/stdc++.h>

using namespace std;

vector<int> linear_sieve(int n) {
    vector<int> lp(n+1), p;
    for(int i = 2; i <= n; i++) {
        if(lp[i] == 0) {
            lp[i] = i;
            p.push_back(i);
        }
        for(int j = 0; i*p[j] <= n; j++) {
            lp[i*p[j]] = p[j];
            if(lp[i] == p[j]) break;
        }
    }
    return lp;
}