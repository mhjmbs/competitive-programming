#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

struct SegmentTree {
    vector<ll> seg, lazy, array;
    int lr_size = 1;
    int lr_start;

    SegmentTree(vector<ll> &vec, vector<ll> &prefix) {
        while(lr_size < prefix.size()) lr_size *= 2;

        seg.resize(2*lr_size - 1, ll(-1e16));
        lazy.resize(2*lr_size - 1, 0);

        lr_start = seg.size() - lr_size;

        for(int i = 0; i < prefix.size(); i++) {
            seg[lr_start + i] = prefix[i];
        }

        for(int i = lr_start - 1; 0 <= i; i--) {
            seg[i] = max(seg[2*i+1], seg[2*i+2]);
        }

        array = vec;
    }

    void update(int k, int u, int lx = 0, int rx = -1, int i = 0) {
        if(rx == -1) rx = lr_size - 1;

        unlazy(i);

        int m = (lx+rx)/2;

        if(rx < k) return;
        else if(k <= lx) lazy[i] += u;
        else {
            update(k, u, lx, m, 2*i+1), update(k, u, m+1, rx, 2*i+2);
            unlazy(2*i+1);unlazy(2*i+2);
            seg[i] = max(seg[2*i+1], seg[2*i+2]);
        }
    }

    void unlazy(int i) {
        seg[i] += lazy[i];
        if(i < lr_start) {
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }

    ll retrieve(int target, int lx = 0, int rx = -1, int i = 0) {
        if(rx == -1) rx = lr_size - 1;

        unlazy(i);

        if(lr_start + target == i) return seg[i];

        int m = (lx + rx)/2;

        if(target <= m) return retrieve(target, lx, m, 2*i+1);
        else return retrieve(target, m+1, rx, 2*i+2);
    }

    ll query(int l, int r, int lx = 0, int rx = -1, int i = 0) {
        if(rx == -1) rx = lr_size-1;

        unlazy(i);

        int m = (lx+rx)/2;

        if(rx < l || r < lx) return ll(-1e16);
        if(l <= lx && rx <= r) return seg[i];
        return max(query(l, r, lx, m, 2*i+1), query(l, r, m+1, rx, 2*i+2));
    }
};

int main() {
    fastio;

    int n, q;
    cin >> n >> q;

    vector<ll> array(n), prefix(n+1, 0);
    for(ll i = 1, inp; i <= n; i++) {
        cin >> inp;
        array[i-1] = inp;
        prefix[i] = prefix[i-1] + inp;
    }

    SegmentTree seg(array, prefix);

    for(int i = 0, tq; i < q; i++) {
        cin >> tq;
        if(tq == 1) {
            int k, u;
            cin >> k >> u;
            seg.update(k, u - seg.array[k-1]);
            seg.array[k-1] = u;
        }else {
            int a, b;
            cin >> a >> b;
            ll ans = seg.query(a, b) - seg.retrieve(a-1);
            if(ans < 0) cout << 0 << endl;
            else cout << ans << endl;
        }
    }
}