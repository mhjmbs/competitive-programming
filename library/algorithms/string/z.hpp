#pragma once

#include <bits/stdc++.h>

using namespace std;

vector<int> z_func(const string &s) {
    vector<int> z(s.size());
    z[0] = 0;

    for(int i = 1, l = 0, r = 0; i < s.size(); i++) {
        if(i < r) {
            z[i] = min(z[i-l], r-i);
        }
        while(i+z[i] < s.size() && s[i+z[i]] == s[z[i]]) {
            z[i]++;
        }
        if(i+z[i] > r) {
            l = i;
            r = i+z[i];
        }
    }

    z[0] = s.size();
    return z;
}