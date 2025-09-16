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

template<typename T, auto Op, T e>
struct SegmentTree {
    vector<T> seg;
    int l0, ln;
 
    SegmentTree(int n) : ln(1) {
        while(ln < n) ln *= 2;
        seg.resize(2*ln-1, e);
        l0 = seg.size() - ln;
    }
 
    SegmentTree(vector<T>& a) : SegmentTree(a.size()) {
        copy(a.begin(), a.end(), seg.begin()+l0);
        for(int i = l0-1; i >= 0; i--) {
            seg[i] = Op(seg[2*i+1], seg[2*i+2]);
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
            seg[i] = Op(seg[2*i+1], seg[2*i+2]);
        }
    }
 
    T query(int l, int r) {
        return query(l, r, 0, ln, 0);
    }
 
    T query(int l, int r, int lx, int rx, int i) {
        if(r <= lx || rx <= l) return e;
        if(l <= lx && rx <= r) return seg[i];
        int m = (lx+rx)/2;
        return Op( query(l, r, lx, m, 2*i+1), query(l, r, m, rx, 2*i+2) );
    }
};

struct Node {
    ll sum;
    ll sz;
};

Node op(Node a, Node b) {
    return 
    {
        a.sum + (a.sz % 2 == 0 ? 1 : -1) * b.sum,
        a.sz + b.sz
    };
}

int main() {
    fastio;

    int n;
    cin >> n;

    vector<Node> a(n);
    for(auto& [sum, sz] : a) {
        cin >> sum;
        sz = 1;
    }

    SegmentTree<Node,op,Node{0,0}> seg(a);

    int q;
    cin >> q;

    while(q--) {
        int type;
        cin >> type;

        if(type == 0) {
            int i, j;
            cin >> i >> j;
            i--;
            seg.set(i, {j,1});
        }else {
            int l, r;
            cin >> l >> r;
            l--,r--;
            cout << seg.query(l, r+1).sum << '\n';
        }
    }
}