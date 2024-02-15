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
    inline static const T neutral = 0;
    vector<T> seg;
    int leafsBegin;
    int leafsCount;

    SegmentTree(const int n) {
        leafsCount = 1;
        while(leafsCount < n) leafsCount *= 2;
        seg.resize(2*leafsCount-1, neutral);
        leafsBegin = seg.size() - leafsCount;
    }

    SegmentTree(const vector<T>& v) : SegmentTree(v.size()) {
        for(int i = 0; i < v.size(); i++) {
            seg[leafsBegin+i] = v[i];
        }
        for(int i = leafsBegin-1; i >= 0; i--) {
            seg[i] = merge(seg[2*i+1], seg[2*i+2]);
        }
    }

    void upd(int i, T val) {
        i = leafsBegin + i;
        seg[i] = val;
        while(i > 0) {
            i = (i-1)/2;
            seg[i] = merge(seg[2*i+1], seg[2*i+2]);
        }
    }

    T query(int l, int r) {
        return query(l, r, 0, leafsCount-1, 0);
    }

    T query(int l, int r, int lx, int rx, int i) {
        if(rx < l || r < lx) return neutral;
        if(l <= lx && rx <= r) return seg[i];
        int mid = (lx+rx)/2;
        return merge( query(l, r, lx, mid, 2*i+1), query(l, r, mid+1, rx, 2*i+2) );
    }

    T merge(T lc, T rc) {
        return lc+rc;
    }
};

int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> p(n);
    for(int& pi : p) cin >> pi;

    SegmentTree<int> seg(n+1);

    vector<int> ans(n);

    for(int i = 0; i < n; i++) {
        ans[i] = seg.query(p[i] + 1, n);
        seg.upd(p[i], 1);
    }

    for(int& x : ans) cout << x << ' ';
    cout << '\n';
}