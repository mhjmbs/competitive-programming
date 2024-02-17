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
    struct Node {
        bool isGood;
        int first;
        int last;
    };

    Node neutral = {true, -1, -1};
    vector<Node> seg;
    vector<bool> lazy;
    int leafsBegin;
    int leafsCount;

    SegmentTree(int n) {
        leafsCount = 1;
        while(leafsCount < n) leafsCount *= 2;
        seg.resize(2*leafsCount-1, neutral);
        lazy.resize(seg.size(), false);
        leafsBegin = seg.size() - leafsCount;
    }

    SegmentTree(const vector<T>& v) : SegmentTree(v.size()) {      
        for(int i = 0; i < v.size(); i++) {
            seg[leafsBegin+i] = {true, v[i], v[i]};
        }
        for(int i = leafsBegin-1; i >= 0; i--) {
            seg[i] = merge(seg[2*i+1], seg[2*i+2]);
        }
    }

    void unlazy(int i) {
        if(lazy[i]) {
            seg[i].first = !seg[i].first;
            seg[i].last = !seg[i].last;
        }
        if(i < leafsBegin) {
            lazy[2*i+1] = lazy[2*i+1] != lazy[i];
            lazy[2*i+2] = lazy[2*i+2] != lazy[i];
        }
        lazy[i] = false;
    }

    void upd(int l, int r) {
        upd(l, r, 0, leafsCount-1, 0);
    }

    void upd(int l, int r, int lx, int rx, int i) {
        int mid = (lx+rx)/2;
        if(rx < l || r < lx) return;
        if(l <= lx && rx <= r) lazy[i] = !lazy[i];
        else {
            upd(l, r, lx, mid, 2*i+1), upd(l, r, mid+1, rx, 2*i+2);
            unlazy(2*i+1), unlazy(2*i+2);
            seg[i] = merge(seg[2*i+1], seg[2*i+2]);
        }
    }

    bool query(int l, int r) {
        return query(l, r, 0, leafsCount-1, 0).isGood;
    }

    Node query(int l, int r, int lx, int rx, int i) {
        unlazy(i);
        if(rx < l || r < lx) return neutral;
        if(l <= lx && rx <= r) return seg[i];
        int mid = (lx+rx)/2;
        return merge( query(l, r, lx, mid, 2*i+1), query(l, r, mid+1, rx, 2*i+2) );
    }

    Node merge(Node lc, Node rc) {
        if(lc.first == -1) return rc;
        if(rc.first == -1) return lc;
        bool good = lc.isGood && rc.isGood && lc.last != rc.first;
        return {good, lc.first, rc.last};
    }
};

int main() {
    fastio;

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> v(n);
    for(int i = 0; i < n; i++) v[i] = s[i] - '0';

    SegmentTree<int> seg(v);

    while(q--) {
        int tq, l, r;
        cin >> tq >> l >> r;
        l--,r--;
        if(tq == 1) seg.upd(l,r);
        else cout << (seg.query(l,r) ? "Yes" : "No") << '\n';
    }
}