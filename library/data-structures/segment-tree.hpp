#pragma once

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

class SegmentTree {
    vector<ll> seg;
    int lr_start;
    int lr_size = 1;

    public:

    SegmentTree(vector<int> vec) {
        while(lr_size < vec.size()) {
            lr_size *= 2;
        }

        seg.resize(2*lr_size-1);
        
        lr_start = seg.size() - lr_size;

        for(int i = 0; i < vec.size(); i++) {
            seg[lr_start + i] = vec[i];
        }

        for(int i = lr_start - 1; 0 <= i; i--) {
            seg[i] = seg[2*i+1] + seg[2*i+2];
        }
    }

    void update(int i, int val) {
        i = lr_start + i;
        seg[i] = val;

        while(i != 0) {
            i = (i-1)/2;
            seg[i] = seg[2*i+1] + seg[2*i+2];
        }
    }

    ll query(int l, int r, int lx = 0, int rx = -1, int i = 0) {
        if(rx == -1) rx = lr_size-1;
        int mid = (lx+rx)/2;

        if(l <= lx && rx <= r) return seg[i];
        else if(rx < l|| r < lx) return 0;
        else return query(l, r, lx, mid, 2*i+1) + query(l, r, mid+1, rx, 2*i+2);
    }
};