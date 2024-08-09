#pragma once

#include <bits/stdc++.h>

using namespace std;

namespace cp {

vector<int> kmp(const string &s) {
    vector<int> pi(s.size());
    pi[0] = 0;

    for(int i = 1, j = 0; i < s.size(); i++) {
        while(j > 0 && s[i] != s[j]) {
            j = pi[j-1];
        }
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }

    return pi;
}

}