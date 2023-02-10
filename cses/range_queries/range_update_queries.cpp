#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

struct SegmentTree {
    vector<ll> seg;
    vector<ll> lazy;
    int lr_size = 1;
    int lr_start;

    SegmentTree(vector<int>& x) {
        setSize(x.size());

        lr_start = seg.size() - lr_size;

        for(int i = 0; i < x.size(); i++) {
            seg[lr_start + i] = x[i];
        }

        lazy.resize(seg.size(), 0);
    }

    void setSize(int array_size) {
        while(lr_size < array_size) lr_size *=2;
        seg.resize(2*lr_size-1,0);
    }

    void update(int l, int r, int u, int lx = 0, int rx = -1, int i = 0) {
        if(rx == -1) rx = lr_size-1;

        int m = (lx+rx)/2;

        if(r < lx || rx < l) return;
        else if(l <= lx && rx <= r) lazy[i] += u;
        else update(l, r, u, lx, m, 2*i+1), update(l, r, u, m+1, rx, 2*i+2);
    }

    ll query(int k, int lx = 0, int rx = -1, int i = 0) {
        if(rx == -1) rx = lr_size-1;

        unlazy(i);

        int m = (lx+rx)/2;

        if(lx == k && rx == k) return seg[i];
        else if(k <= m) return query(k, lx, m, 2*i+1);
        else return query(k, m+1, rx, 2*i+2);
    }

    void unlazy(int i) {
        if(lazy[i] != 0) {
            if(lr_start <= i) {
                seg[i] += lazy[i];
            }else {
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i] = 0;
        }
    }
};

int main() {
    fastio;

    int n, q;
    cin >> n >> q;

    vector<int> x(n);
    for(int &xi : x) cin >> xi;

    SegmentTree seg(x);

    for(int i = 0, tq; i < q; i++) {
        cin >> tq;
        if(tq == 1) {
            int l, r, u;
            cin >> l >> r >> u;
            l--;r--;
            seg.update(l, r, u);
        }else {
            int k;
            cin >> k;
            k--;
            cout << seg.query(k) << '\n';
        }
    }
}