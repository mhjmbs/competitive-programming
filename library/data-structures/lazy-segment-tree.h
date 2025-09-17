#pragma once

#include "../contest/template.cpp"

template<class T, auto op, auto e, class U, auto upd_op, auto upd_e, auto comp>
struct LazySegmentTree {
    vector<T> seg;
    vector<U> lazy;
    vector<optional<T>> to_set;
    int l0, ln;
    
    LazySegmentTree(int n) : ln(1) {
        while(ln < n) ln *= 2;
        seg.resize(2*ln-1, e());
        lazy.resize(seg.size(), upd_e());
        to_set.resize(seg.size());
        l0 = seg.size() - ln;
    }
    
    LazySegmentTree(const vector<T>& a) : LazySegmentTree(a.size()) {
        copy(a.begin(), a.end(), seg.begin()+l0);
        for(int i = l0-1; i >= 0; i--) {
            seg[i] = op(seg[2*i+1], seg[2*i+2]);
        }
    }

    void unlazy(int i, int lx, int rx) {
        if(to_set[i]) {
            seg[i] = to_set[i].value();
            if(i < l0) {
                to_set[2*i+1] = to_set[i];
                to_set[2*i+2] = to_set[i];
                lazy[2*i+1] = lazy[2*i+2] = upd_e();
            }
            to_set[i].reset();
        }
        seg[i] = upd_op(seg[i], lazy[i]);
        if(i < l0) {
            lazy[2*i+1] = comp(lazy[i], lazy[2*i+1]);
            lazy[2*i+2] = comp(lazy[i], lazy[2*i+2]);
        }
        lazy[i] = upd_e();
    }
    
    void set(int l, int r, T val) {
        set(l, r, val, 0, ln, 0);
    }

    void set(int l, int r, T val, int lx, int rx, int i) {
        unlazy(i,lx,rx);
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r) {
            to_set[i] = val;
            lazy[i] = upd_e();
            unlazy(i,lx,rx);
            return;
        }
        int m = (lx+rx)/2;
        set(l, r, val, lx, m, 2*i+1);
        set(l, r, val, m, rx, 2*i+2);
        seg[i] = op(seg[2*i+1], seg[2*i+2]);
    }

    void upd(int l, int r, U val) {
        upd(l, r, val, 0, ln, 0);
    }

    void upd(int l, int r, U val, int lx, int rx, int i) {
        unlazy(i,lx,rx);
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r) {
            lazy[i] = comp(lazy[i], val);
            unlazy(i,lx,rx);
            return;
        }
        int m = (lx+rx)/2;
        upd(l, r, val, lx, m, 2*i+1);
        upd(l, r, val, m, rx, 2*i+2);
        seg[i] = op(seg[2*i+1], seg[2*i+2]);
    }

    T query(int l, int r) {
        return query(l, r, 0, ln, 0);
    }

    T query(int l, int r, int lx, int rx, int i) {
        unlazy(i,lx,rx);
        if(rx <= l || r <= lx) return e();
        if(l <= lx && rx <= r) return seg[i];
        int m = (lx+rx)/2;
        return op(query(l, r, lx, m, 2*i+1), query(l, r, m, rx, 2*i+2));
    }
};