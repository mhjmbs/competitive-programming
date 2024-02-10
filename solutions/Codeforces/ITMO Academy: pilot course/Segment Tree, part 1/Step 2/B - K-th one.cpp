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

    SegmentTree(const vector<T>& v) {
        leafsCount = 1;
        while(leafsCount < v.size()) leafsCount *= 2;
        seg.resize(2*leafsCount-1, neutral);
        leafsBegin = seg.size() - leafsCount;

        for(int i = 0; i < v.size(); i++) {
            seg[leafsBegin+i] = v[i];
        }

        for(int i = leafsBegin-1; i >= 0; i--) {
            seg[i] = merge(seg[2*i+1], seg[2*i+2]);
        }
    }

    void upd(int i) {
        i = leafsBegin+i;
        seg[i] = !seg[i];
        while(i > 0) {
            i = (i-1)/2;
            seg[i] = merge(seg[2*i+1], seg[2*i+2]);
        }
    }

    T query(int k) {
        return query(k, 0, 0, leafsCount-1, 0);
    }

    T query(int k, int accum, int lx, int rx, int i) {
        int mid = (lx+rx)/2;
        if(lx == rx) return rx;
        if(k <= accum + seg[2*i+1]) return query(k, accum, lx, mid, 2*i+1);
        return query(k, accum+seg[2*i+1], mid+1, rx, 2*i+2);
    }

    T merge(T a, T b) {
        return a+b;
    }
};

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int& ai : a) cin >> ai;

    SegmentTree<int> seg(a);

    while(m--) {
        int t;
        cin >> t;

        if(t == 1) {
            int i;
            cin >> i;
            seg.upd(i);
        }else {
            int k;
            cin >> k;
            cout << seg.query(k+1) << '\n';
        }
    }
}