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
        i = l0+i;
        T ans = seg[i];
        while(i > 0) {
            i = (i-1)/2;
            ans += seg[i];
        }
        return ans;
    }
 
    void upd(int l, int r, T val) {
        upd(l, r, val, 0, ln, 0);
    }
 
    void upd(int l, int r, T val, int lx, int rx, int i) {
        if(r <= lx || rx <= l) return;
        if(l <= lx && rx <= r) {
            seg[i] += val;
            return;
        }
        int m = (lx+rx)/2;
        upd(l, r, val, lx, m, 2*i+1), upd(l, r, val, m, rx, 2*i+2);
    }
};

ll add(ll a, ll b) {
    return a+b;
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    SegmentTree<ll,add,0> seg(n);

    while(m--) {
        int type;
        cin >> type;

        if(type == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            seg.upd(l,r,v);
        }else {
            int i;
            cin >> i;
            cout << seg.get(i) << '\n';
        }
    }
}