#pragma once

#include <bits/stdc++.h>

using namespace std;

template <typename T>
class SegmentTree {
    vector<T> seg;
    int leafsBegin;
    int leafsCount;

    T op(T a, T b) {
        return a + b;
    }

    T neutral() {
        return 0;
    }

    public:

    SegmentTree(const vector<T>& vec) {
        leafsCount = 1;

        while(leafsCount < vec.size()) {
            leafsCount *= 2;
        }

        seg.resize(2*leafsCount-1, neutral());
        
        leafsBegin = seg.size() - leafsCount;

        for(int i = 0; i < vec.size(); i++) {
            seg[leafsBegin + i] = vec[i];
        }

        for(int i = leafsBegin - 1; i >= 0; i--) {
            seg[i] = op(seg[2*i+1], seg[2*i+2]);
        }
    }

    void update(int i, int val) {
        i = leafsBegin + i;
        seg[i] = val;

        while(i != 0) {
            i = (i-1)/2;
            seg[i] = op(seg[2*i+1], seg[2*i+2]);
        }
    }

    T query(int l, int r) {
        return query(l, r, 0, leafsCount-1, 0);
    }

    T query(int l, int r, int lx, int rx, int i) {
        int mid = (lx+rx)/2;

        if(l <= lx && rx <= r) return seg[i];
        else if(rx < l|| r < lx) return neutral();
        else return op( query(l, r, lx, mid, 2*i+1), query(l, r, mid+1, rx, 2*i+2) );
    }
};