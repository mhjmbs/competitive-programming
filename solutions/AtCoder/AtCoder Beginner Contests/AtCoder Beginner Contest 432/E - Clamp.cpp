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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T, auto op, auto e>
struct SegmentTree {
    vector<T> seg;
    int l0, ln;
 
    SegmentTree(int n) : ln(1) {
        while(ln < n) ln *= 2;
        seg.resize(2*ln-1, e());
        l0 = seg.size() - ln;
    }
 
    SegmentTree(const vector<T>& a) : SegmentTree(a.size()) {
        copy(a.begin(), a.end(), seg.begin()+l0);
        for(int i = l0-1; i >= 0; i--) {
            seg[i] = op(seg[2*i+1], seg[2*i+2]);
        }
    }
 
    T get(int i) {
        return seg[l0+i];
    }
 
    void set(int i, T x) {
        i = l0+i;
        seg[i] = x;
        while(i > 0) {
            i = (i-1)/2;
            seg[i] = op(seg[2*i+1], seg[2*i+2]);
        }
    }
 
    T query(int l, int r) {
        return query(l, r, 0, ln, 0);
    }
 
    T query(int l, int r, int lx, int rx, int i) {
        if(r <= lx || rx <= l) return e();
        if(l <= lx && rx <= r) return seg[i];
        int m = (lx+rx)/2;
        return op( query(l, r, lx, m, 2*i+1), query(l, r, m, rx, 2*i+2) );
    }
};

struct Node {
    ll sum;
    ll cnt;
};

int main() {
    fastio;

    int n, q;
    cin >> n >> q;

    vector<int> a(n+1);
    SegmentTree<
        Node,
        [](Node a, Node b) {return Node{a.sum+b.sum,a.cnt+b.cnt};},
        []() {return Node{0,0};}
    >
    seg(5*1e5+1);

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        seg.set(a[i], {seg.get(a[i]).sum+a[i], seg.get(a[i]).cnt+1});
    }

    while(q--) {
        int type;
        cin >> type;

        if(type == 1) {
            int x, y;
            cin >> x >> y;
            seg.set(a[x], {seg.get(a[x]).sum-a[x],seg.get(a[x]).cnt-1});
            a[x] = y;
            seg.set(a[x], {seg.get(a[x]).sum+a[x],seg.get(a[x]).cnt+1});
        }else {
            int l, r;
            cin >> l >> r;
            if(l <= r) {
                cout << seg.query(l,r+1).sum + seg.query(0,l).cnt*l + seg.query(r+1,5*1e5+1).cnt*r << '\n';
            }else {
                cout << seg.query(0,5*1e5+1).cnt*l << '\n';
            }
        }
    }
}