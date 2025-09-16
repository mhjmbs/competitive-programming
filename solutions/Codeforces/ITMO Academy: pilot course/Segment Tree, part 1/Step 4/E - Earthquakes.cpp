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
using ordered_multiset = tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;

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
 
    T query(int l, int r, int p) {
        return query(l, r, p, 0, ln, 0);
    }
 
    T query(int l, int r, int p, int lx, int rx, int i) {
        if(r <= lx || rx <= l) return 0;
        if(l <= lx && rx <= r) return cleanup(lx, rx, p, i);
        int m = (lx+rx)/2;
        return query(l, r, p, lx, m, 2*i+1) + query(l, r, p, m, rx, 2*i+2);
    }

    T cleanup(int lx, int rx, int p, int i) {
        if(l0 <= i) {
            if(seg[i] <= p) {
                set(i-l0, e);
                return 1;
            }
            return 0;
        }
        int m = (lx+rx)/2;
        int ans = 0;
        if(seg[2*i+1] <= p) ans += cleanup(lx, m, p, 2*i+1);
        if(seg[2*i+2] <= p) ans += cleanup(m, rx, p, 2*i+2);
        return ans;
    }
};

int op(int a, int b) {
    return min(a,b);
}

int main() {
    fastio;

    int n, q;
    cin >> n >> q;

    SegmentTree<int,op,INT_MAX> seg(n);
    
    while(q--) {
        int type;
        cin >> type;

        if(type == 1) {
            int i, h;
            cin >> i >> h;
            seg.set(i, h);
        }else {
            int l, r, p;
            cin >> l >> r >> p;
            cout << seg.query(l, r, p) << '\n';
        }
    }
}