#pragma once

#include <bits/stdc++.h>

using namespace std;

constexpr auto Min = [](auto a, auto b) { return min(a, b); };
constexpr auto Max = [](auto a, auto b) { return max(a, b); };

template <typename T, auto Op, T e>
struct SparseTable {
    int n, lg;
    vector<vector<T>> t;
    
    SparseTable() = default;
    
    SparseTable(vector<T>& v) : n(v.size()), lg(__lg(n)), t(lg+1, vector<T>(n)) {
        t[0] = v;
        for(int k = 1; k < lg+1; k++) {
            for(int i = 0; i <= n-(1<<k); i++) {
                t[k][i] = Op(t[k-1][i], t[k-1][i+(1<<(k-1))]);
            }
        }
    }
    
    T rmq(int l, int r) {
        if(l > r) return e;
        int k = __lg(r-l+1);
        return Op(t[k][l], t[k][r-(1<<k)+1]);
    }
    
    T q(int l, int r) {
        T ans = e;
        int sz = r-l+1, k = 0;
        while(sz > 0) {
            if(sz&1) {
                ans = Op(ans, t[k][l]);
                l += (1<<k);
            }
            k++;
            sz >>= 1;
        }
        return ans;
    }
};