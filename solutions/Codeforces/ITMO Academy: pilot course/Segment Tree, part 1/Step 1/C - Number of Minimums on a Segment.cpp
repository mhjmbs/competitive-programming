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
    inline static const T neutral = {numeric_limits<int>::max(), 0};
    vector<T> seg;
    int leafsBegin;
    int leafsCount;

    SegmentTree(const vector<int>& v) {
        leafsCount = 1;
        while(leafsCount < v.size()) leafsCount *= 2;
        seg.resize(2*leafsCount-1, neutral);
        
        leafsBegin = seg.size() - leafsCount;

        for(int i = 0; i < v.size(); i++) {
            seg[leafsBegin+i] = {v[i],1};
        }

        for(int i = leafsBegin-1; i >= 0; i--) {
            seg[i] = merge(seg[2*i+1], seg[2*i+2]);
        }
    }

    void upd(int i, int val) {
        i = leafsBegin + i;
        seg[i] = {val,1};
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

    T merge(T a, T b) {
        if(a.first == b.first) return {a.first, a.second+b.second};
        return min(a,b);
    }
};

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int& ai : a) cin >> ai;

    SegmentTree<pii> seg(a);

    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;

        if(t == 1) {
            int i, v;
            cin >> i >> v;
            seg.upd(i,v);
        }else {
            int l, r;
            cin >> l >> r;
            pii ans = seg.query(l,r-1);
            cout << ans.first << ' ' << ans.second << '\n';
        }
    }
}