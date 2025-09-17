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

template<class T, auto op, auto e, class U, auto upd_op, auto upd_e, auto comp>
struct LazySegmentTree {
    vector<T> seg;
    vector<U> lazy;
    vector<optional<T>> to_set;
    int l0, ln;
    
    LazySegmentTree(int n) : ln(1) {
        while(ln < n) ln *= 2;
        seg.resize(2*ln-1, e());
        lazy.resize(seg.size(), upd_e());
        to_set.resize(seg.size());
        l0 = seg.size() - ln;
    }
    
    LazySegmentTree(const vector<T>& a) : LazySegmentTree(a.size()) {
        copy(a.begin(), a.end(), seg.begin()+l0);
        for(int i = l0-1; i >= 0; i--) {
            seg[i] = op(seg[2*i+1], seg[2*i+2]);
        }
    }

    void unlazy(int i, int lx, int rx) {
        if(to_set[i]) {
            seg[i] = to_set[i].value()*(rx-lx);
            if(i < l0) {
                to_set[2*i+1] = to_set[i];
                to_set[2*i+2] = to_set[i];
                lazy[2*i+1] = lazy[2*i+2] = upd_e();
            }
            to_set[i].reset();
        }
        seg[i] = upd_op(seg[i], lazy[i]*(rx-lx));
        if(i < l0) {
            lazy[2*i+1] = comp(lazy[i], lazy[2*i+1]);
            lazy[2*i+2] = comp(lazy[i], lazy[2*i+2]);
        }
        lazy[i] = upd_e();
    }
    
    void set(int l, int r, T val) {
        set(l, r, val, 0, ln, 0);
    }

    void set(int l, int r, T val, int lx, int rx, int i) {
        unlazy(i,lx,rx);
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r) {
            to_set[i] = val;
            lazy[i] = upd_e();
            unlazy(i,lx,rx);
            return;
        }
        int m = (lx+rx)/2;
        set(l, r, val, lx, m, 2*i+1);
        set(l, r, val, m, rx, 2*i+2);
        seg[i] = op(seg[2*i+1], seg[2*i+2]);
    }

    void upd(int l, int r, U val) {
        upd(l, r, val, 0, ln, 0);
    }

    void upd(int l, int r, U val, int lx, int rx, int i) {
        unlazy(i,lx,rx);
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r) {
            lazy[i] = comp(lazy[i], val);
            unlazy(i,lx,rx);
            return;
        }
        int m = (lx+rx)/2;
        upd(l, r, val, lx, m, 2*i+1);
        upd(l, r, val, m, rx, 2*i+2);
        seg[i] = op(seg[2*i+1], seg[2*i+2]);
    }

    T query(int l, int r) {
        return query(l, r, 0, ln, 0);
    }

    T query(int l, int r, int lx, int rx, int i) {
        unlazy(i,lx,rx);
        if(rx <= l || r <= lx) return e();
        if(l <= lx && rx <= r) return seg[i];
        int m = (lx+rx)/2;
        return op(query(l, r, lx, m, 2*i+1), query(l, r, m, rx, 2*i+2));
    }
};

ll add(ll a, ll b) {
    return a+b;
}

ll e() {
    return 0;
}

int main() {
    fastio;

    int n, q;
    cin >> n >> q;

    vector<ll> t(n);
    for(ll& ti : t) cin >> ti;

    LazySegmentTree<ll,add,e,ll,add,e,add> seg(t);

    while(q--) {
        int type;
        cin >> type;

        if(type == 1) {
            int a, b, x;
            cin >> a >> b >> x;
            a--,b--;
            seg.upd(a,b+1,x);
        }else if(type == 2) {
            int a, b, x;
            cin >> a >> b >> x;
            a--,b--;
            seg.set(a,b+1,x);
        }else {
            int a, b;
            cin >> a >> b;
            a--,b--;
            cout << seg.query(a,b+1) << '\n';
        }
    }
}