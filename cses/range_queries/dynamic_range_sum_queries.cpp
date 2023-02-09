#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

struct SegTree {
    vector<ll> seg;
    int lr_size = 1;
    int lr_start;

    SegTree(vector<int> x) {
        setSize(x.size());

        lr_start = seg.size() - lr_size;

        for(int i = 0; i < lr_size; i++) {
            seg[lr_start + i] = x[i];
        }

        for(int i = lr_start-1; 0 <= i; i--) {
            seg[i] = seg[2*i+1] + seg[2*i+2];
        }
    }

    void setSize(int array_size) {
        while(lr_size < array_size) lr_size *= 2;
        seg.resize(2*lr_size-1, 0);
    }

    void set(int k, int u) {
        int i = lr_start + k;
        seg[i] = u;

        while(i > 0) {
            if(i % 2 == 0) i = (i-2)/2;
            else i = (i-1)/2;

            seg[i] = seg[2*i+1] + seg[2*i+2];
        }
    }

    ll query(int l, int r, int lx = 0, int rx = -1, int i = 0) {
        if(rx == -1) rx = lr_size-1;

        int m = (lx+rx)/2;

        if(rx < l || r < lx) return 0;
        if(l <= lx && rx <= r) return seg[i];
        return query(l, r, lx, m, 2*i+1) + query(l, r, m+1, rx, 2*i+2);
    }
};

int main() {
    fastio;

    int n, q;
    cin >> n >> q;

    vector<int> x(n);
    for(int &num : x) cin >> num;
    
    SegTree seg(x);

    for(int i = 0, tq; i < q; i++) {
        cin >> tq;
        if(tq == 1){
            int k, u;
            cin >> k >> u;
            k--;
            seg.set(k, u);
        }else {
            int l, r;
            cin >> l >> r;
            l--;r--;
            cout << seg.query(l, r) << '\n';
        }
    }
}