#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

struct SegmentTree {
    vector<int> seg;
    int lr_size = 1;
    int lr_start;

    SegmentTree(int n) {
        while(lr_size < n) lr_size *= 2;
        seg.resize(2*lr_size-1, 0);
        lr_start = seg.size() - lr_size;
    }

    void update(int i) {
        i = lr_start + i;
        seg[i] = query(0, (i-lr_start)-1)+1;

        while(i != 0) {
            if(i % 2 == 0) i = (i-2)/2;
            else i = (i-1)/2;
            seg[i] = max(seg[2*i+1], seg[2*i+2]);
        }
    }

    int query(int l, int r, int lx = 0, int rx = -1, int i = 0) {
        if(rx == -1) rx = lr_size-1;

        int m = (lx+rx)/2;

        if(l <= lx && rx <= r) return seg[i];
        if(r < lx || rx < l) return 0;
        return max(query(l, r, lx, m, 2*i+1), query(l, r, m+1, rx, 2*i+2));
    }
};

int main() {
    fastio;

    int n;
    cin >> n;

    SegmentTree seg(n);

    vector<pii> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i].first;
        x[i].second = i;
    }

    auto comp = [](pii a, pii b) {
        if(a.first < b.first) return true;
        if(a.first > b.first) return false;
        return a.second > b.second;
    };
    sort(x.begin(), x.end(), comp);

    int ans = 0;

    for(pii xi : x) {
        seg.update(xi.second);
        ans = max(ans, seg.query(0, n-1));
    }

    cout << ans << '\n';
}