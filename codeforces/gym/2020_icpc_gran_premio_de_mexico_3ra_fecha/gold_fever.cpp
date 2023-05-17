#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pip = pair<int,pii>;

struct SegmentTree {
    vector<int> seg;
    int lr_size = 1;
    int lr_start;

    SegmentTree(int n) {
        while(lr_size < n) lr_size *= 2;
        seg.resize(2*lr_size-1, 0);
        lr_start = seg.size() - lr_size;
    }

    void update(int i, int v) {
        i = lr_start + i;

        seg[i] = v;

        while(i != 0) {
            if(i % 2 == 0) i = (i-2)/2;
            else i = (i-1)/2;
            seg[i] = max(seg[2*i+1], seg[2*i+2]);
        }
    }

    int query(int l, int r, int lx = 0, int rx = -1, int i = 0) {
        if(rx == -1) rx = lr_size-1;

        int m = (lx+rx)/2;

        if(rx < l || r < lx) return 0;
        if(l <= lx && rx <= r) return seg[i];
        return max(query(l, r, lx, m, 2*i+1), query(l, r, m+1, rx, 2*i+2));
    }

};

int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> g(n+1), a(n+1), b(n+1);
    for(int i = 1; i <= n; i++)
        cin >> g[i] >> a[i] >> b[i];

    SegmentTree seg(n+1);

    int max_ans = INT_MIN;

    for(int i = n; 1 <= i; i--) {
        int curr_ans = g[i] + seg.query(i+a[i], i+b[i]);
        seg.update(i, curr_ans);
        max_ans = max(max_ans, curr_ans);
    }

    cout << max_ans << '\n';
}