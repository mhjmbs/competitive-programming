#pragma once

#include "../contest/template.cpp"

template<typename T>
struct FenwickTree {
    int n;
    vector<T> tree;

    FenwickTree(int n) : n{n}, tree(n+1) 
    {}

    FenwickTree(const vector<T>& v) : FenwickTree(v.size()) {
        for(int i = 1; i <= n; i++) {
            tree[i] += v[i-1];
            if(i+(i&-i) <= n) {
                tree[i+(i&-i)] += tree[i];
            }
        }
    }

    void sum(int i, T val) {
        while(i <= n) {
            tree[i] += val;
            i += i&-i;
        }
    }

    T query(int l, int r) {
        return query(r) - query(l-1);
    }

    T query(int r) {
        T ans = 0;
        while(r > 0) {
            ans += tree[r];
            r -= r&-r;
        }
        return ans;
    }

    int lower_bound(T val) {
        int pos = 0;
        T sum = 0;
        for(int i = __lg(n); i >= 0; i--) {
            if(pos+(1<<i) <= n && sum+tree[pos+(1<<i)] < val) {
                sum += tree[pos+(1<<i)];
                pos += 1<<i;
            }
        }
        return pos+1;
    }
};