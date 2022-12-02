#include "bits/stdc++.h"

using namespace std;
using ll = long long;

struct segtree {
    int lrStart;
    int lrSize = 1;
    vector<ll> st;

    segtree(vector<int>& a) {
        setSize(a.size());
        lrStart = st.size() - lrSize;

        for(int i = lrStart; i - lrStart < a.size(); i++) {
            st[i] = a[i - lrStart];
        }
        
        for(int i = lrStart-1; i >= 0; i--) {
            st[i] = st[2*i+1] + st[2*i+2];
        }
    }

    void setSize(int initSize) {
        while(lrSize < initSize) {
            lrSize *= 2;
        }

        st.resize(2*lrSize - 1, 0);
    }

    void set(int i, int v) {
        i = lrStart + i;
        st[i] = v;

        while(i > 0) {
            if(i % 2 == 0) {
                st[(i-2)/2] = st[i] + st[i-1];
                i = (i-2)/2;
            }else {
                st[(i-1)/2] = st[i] + st[i+1];
                i = (i-1)/2;
            }
        }
    }

    ll query(int l, int r, int lx = 0, int rx = -1, int i = 0) {
        if(rx == -1) {
            rx = lrSize-1;
        }

        if(l <= lx && rx <= r) {
            return st[i];
        }else if(rx < l || r < lx) {
            return 0;
        }else {
            int m = lx + (rx-lx)/2;
            return query(l, r, lx, m, 2*i+1) + query(l, r, m+1, rx, 2*i+2);
        }
    }
};

int main() {
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int& ai : a) cin >> ai;
    
    segtree st(a);

    for(int k = 0, q; k < m; k++) {
        cin >> q;
        if(q == 1) {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }else {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r-1) << '\n';
        }
    }
}