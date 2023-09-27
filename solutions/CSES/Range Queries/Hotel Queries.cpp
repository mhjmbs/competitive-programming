#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

struct SegmentTree {
    vector<int> seg;
    int lr_size = 1;
    int lr_start;
    int v_size;

    SegmentTree(vector<int> &v) {
        v_size = v.size();
        while(lr_size < v.size()) lr_size *= 2;
        seg.resize(2*lr_size-1, INT_MIN);

        lr_start = seg.size() - lr_size;

        for(int i = 0; i < v.size(); i++) {
            seg[lr_start + i] = v[i];
        }

        for(int i = lr_start-1; 0 <= i; i--) {
            seg[i] = max(seg[2*i+1], seg[2*i+2]);
        }
    }

    void update(int i, int x) {
        seg[i] = x;

        while(0 < i) {
            if(i % 2 == 0) i = (i-2)/2; 
            else i = (i-1)/2;

            seg[i] = max(seg[2*i+1], seg[2*i+2]);
        }
    }

    int query(int x, int lx = 0, int rx = -1, int i = 0) {
        if(rx == -1) rx = lr_size-1;

        if(lr_start <= i) {
            if(i != lr_start + v_size - 1){
                update(i, seg[i]-x);
                return i-lr_start+1;
            }else {
                return 0;
            }
        }

        int m = (lx+rx)/2; 

        if(seg[2*i+1] >= x) return query(x, lx, m, 2*i+1);
        return query(x, m+1, rx, 2*i+2);
    }
};

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    vector<int> h(n+1, INT_MAX);
    for(int i = 0; i < n; i++) cin >> h[i];

    vector<int> r(m);
    for(int &ri : r) cin >> ri;

    vector<int> ans(m);
    
    SegmentTree seg(h);

    for(int i = 0; i < m; i++) {
        ans[i] = seg.query(r[i]);
    }

    for(int i = 0; i < m; i++) {
        cout << ans[i];
        if(i != m-1) cout << ' ';
        else cout << '\n';
    }

}