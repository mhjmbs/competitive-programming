#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
struct SegmentTree {
    inline static const T neutral = 0LL;
    vector<T> seg, lazy;
    int leafsBegin;
    int leafsCount;

    SegmentTree(const vector<T>& v) {
        leafsCount = 1;
        while(leafsCount < v.size()) leafsCount *= 2;
        seg.resize(2*leafsCount-1, neutral);
        lazy.resize(seg.size(), neutral);

        leafsBegin = seg.size() - leafsCount;

        for(int i = 0; i < v.size(); i++) {
            seg[leafsBegin+i] = v[i];
        }

        for(int i = leafsBegin-1; i >= 0; i--) {
            seg[i] = merge(seg[2*i+1], seg[2*i+2]);
        }
    }

    void unlazy(int lx, int rx, int i) {
        seg[i] += lazy[i];
        if(lx != rx) {
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }

    void sum(int l, int r, T val) {
        sum(l, r, 0, leafsCount-1, 0, val);
    }

    void sum(int l, int r, int lx, int rx, int i, T val) {
        if(r < lx || rx < l) return;
        if(l <= lx && rx <= r) lazy[i] += val;
        else {
            unlazy(lx, rx, i);
            int mid = (lx+rx)/2;
            sum(l, r, lx, mid, 2*i+1, val);
            sum(l, r, mid+1, rx, 2*i+2, val);
        }
    }

    T get(int i) {
        return get(i, 0, leafsCount-1, 0);
    }

    T get(int i, int lx, int rx, int segI) {
        unlazy(lx, rx, segI);
        if(lx == rx) return seg[segI];
        int mid = (lx + rx)/2;
        if(i <= mid) return get(i, lx, mid, 2*segI+1);
        return get(i, mid+1, rx, 2*segI+2);
    }

    T merge(T lc, T rc) {
        return lc+rc;
    }
};

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for(ll& ai : a) cin >> ai;

    SegmentTree<ll> seg(a);

    while(m--) {
        int bi;
        cin >> bi;

        ll curr = seg.get(bi);
        seg.sum(bi,bi,-curr);

        ll full = curr/n;
        seg.sum(0, n-1, full);
        curr -= full*n;

        if((bi+1) + curr - 1 <= n-1) {
            seg.sum(bi+1, bi+1 + curr - 1, 1);
        }else {
            if(bi+1 <= n-1) {
                seg.sum(bi+1, n-1, 1);
                curr -= n-1 - (bi+1) + 1;
            }
            seg.sum(0, curr-1, 1);
        }
    }
    for(int i = 0; i < n; i++) {
        cout << seg.get(i) << ' ';
    }
    cout << endl;
}