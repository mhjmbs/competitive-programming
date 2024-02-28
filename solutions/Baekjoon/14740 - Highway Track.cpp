#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

struct SegmentTree {
    vector<ll> seg, lazy;
    int leafsBegin;
    int leafsCount;

    SegmentTree(int n) {
        leafsCount = 1;
        while(leafsCount < n) leafsCount *= 2;
        seg.resize(2*leafsCount-1, LONG_LONG_MAX);
        lazy.resize(seg.size());
        leafsBegin = seg.size() - leafsCount;
    }

    SegmentTree(vector<ll>& v) : SegmentTree(v.size()) {
        for(int i = 0; i < v.size(); i++) {
            seg[leafsBegin+i] = v[i];
        }
        for(int i = leafsBegin-1; i >= 0; i--) {
            seg[i] = min(seg[2*i+1], seg[2*i+2]);
        }
    }

    void unlazy(int i) {
        seg[i] += lazy[i];
        if(i < leafsBegin) {
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }

    void sum(int l, int r, ll val) {
        sum(l, r, val, 0, leafsCount-1, 0);
    }

    void sum(int l, int r, ll val, int lx, int rx, int i) {
        unlazy(i);
        int mid = (lx+rx)/2;
        if(r < lx || rx < l) return;
        if(l <= lx && rx <= r) lazy[i] += val;
        else {
            sum(l, r, val, lx, mid, 2*i+1), sum(l, r, val, mid+1, rx, 2*i+2);
            unlazy(2*i+1), unlazy(2*i+2);
            seg[i] = min(seg[2*i+1], seg[2*i+2]);
        }
    }

    ll query(int l, int r) {
        return query(l, r, 0, leafsCount-1, 0);
    }

    ll query(int l, int r, int lx, int rx, int i) {
        unlazy(i);
        int mid = (lx+rx)/2;
        if(r < lx || rx < l) return LONG_LONG_MAX;
        if(l <= lx && rx <= r) return seg[i];
        return min(query(l, r, lx, mid, 2*i+1), query(l, r, mid+1, rx, 2*i+2));
    }

};

int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> g(n), d(n);
    for(int& gi : g) cin >> gi;
    for(int& di : d) cin >> di;

    vector<ll> v(n,0);
    for(int i = 0; i < n; i++) {
        v[(i+1) % n] = v[i] + g[i] - d[i];
    }

    SegmentTree seg(v);

    int ans = 0;

    for(int i = 0; i < n; i++) {
        if(seg.query(0,n-1) >= 0) ans++;

        seg.sum(0,n-1,-(g[i]-d[i]));
        seg.sum((i+1)%n, (i+1)%n, seg.query(i,i) + g[i] - d[i]);
    }

    cout << ans << '\n';
}