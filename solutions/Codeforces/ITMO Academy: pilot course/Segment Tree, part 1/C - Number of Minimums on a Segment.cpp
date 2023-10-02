#include "bits/stdc++.h"

using namespace std;
using pii = pair<int,int>;

struct segtree {
    int lrStart;
    int lrSize = 1;
    vector<pii> st;

    segtree(vector<int>& a) {
        setSize(a.size());
        lrStart = st.size() - lrSize;

        for(int i = lrStart; i - lrStart < a.size(); i++) {
            st[i] = {a[i - lrStart], 1};
        }
        
        for(int i = lrStart-1; i >= 0; i--) {
            pii lc = st[2*i+1], rc = st[2*i+2];
            if(lc.first == rc.first) {
                st[i] = {lc.first, lc.second + rc.second};
            }else {
                st[i] = min(lc, rc);
            }
        }
    }

    void setSize(int initSize) {
        while(lrSize < initSize) {
            lrSize *= 2;
        }

        st.resize(2*lrSize - 1, {INT_MAX, 1});
    }

    void set(int i, int v) {
        i = lrStart + i;
        st[i] = {v, 1};

        while(i > 0) {
            if(i % 2 == 0) {
                if(st[i].first == st[i-1].first) {
                    st[(i-2)/2] = {st[i].first, st[i].second + st[i-1].second};
                }else {
                    st[(i-2)/2] = min(st[i], st[i-1]);
                }
                i = (i-2)/2;
            }else {
                if(st[i].first == st[i+1].first) {
                    st[(i-1)/2] = {st[i].first, st[i].second + st[i+1].second};
                }else {
                    st[(i-1)/2] = min(st[i], st[i+1]);
                }
                i = (i-1)/2;
            }
        }
    }

    pii query(int l, int r, int lx = 0, int rx = -1, int i = 0) {
        if(rx == -1) {
            rx = lrSize-1;
        }

        if(l <= lx && rx <= r) {
            return st[i];
        }else if(rx < l || r < lx) {
            return {INT_MAX,1};
        }else {
            int m = lx + (rx-lx)/2;
            pii lc = query(l, r, lx, m, 2*i+1), rc = query(l, r, m+1, rx, 2*i+2);
            if(lc.first == rc.first) {
                return {lc.first, lc.second + rc.second};
            }else {
                return min(lc, rc);
            }
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
            pii ans = st.query(l, r-1);
            cout << ans.first << ' ' << ans.second << '\n';
        }
    }
}