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

struct SegmentTree {
    vector<int> seg, lazy;
    int l0, ln;
 
    SegmentTree(int n) : ln(1) {
        while(ln < n) ln *= 2;
        seg.resize(2*ln-1, (1<<30)-1);
        lazy.resize(seg.size(), 0);
        l0 = seg.size() - ln;
    }
 
    SegmentTree(const vector<int>& a) : SegmentTree(a.size()) {
        copy(a.begin(), a.end(), seg.begin()+l0);
        for(int i = l0-1; i >= 0; i--) {
            seg[i] = seg[2*i+1] & seg[2*i+2];
        }
    }
 
    void upd(int l, int r, int val) {
        upd(l, r, val, 0, ln, 0);
    }

    void upd(int l, int r, int val, int lx, int rx, int i) {
        if(r <= lx || rx <= l) return;
        if(l <= lx && rx <= r) {
            lazy[i] |= val;
            seg[i] |= val;
            return;
        }
        int m = (lx+rx)/2;
        upd(l, r, val, lx, m, 2*i+1), upd(l, r, val, m, rx, 2*i+2);
        seg[i] = (seg[2*i+1] & seg[2*i+2]) | lazy[i];
    }
 
    int query(int l, int r) {
        return query(l, r, 0, ln, 0);
    }
 
    int query(int l, int r, int lx, int rx, int i) {
        if(r <= lx || rx <= l) return (1<<30)-1;
        if(l <= lx && rx <= r) return seg[i];
        int m = (lx+rx)/2;
        return (query(l, r, lx, m, 2*i+1) & query(l, r, m, rx, 2*i+2)) | lazy[i];
    }
};

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    SegmentTree seg(vector<int>(n, 0));

    while(m--) {
        int type, l, r;
        cin >> type >> l >> r;

        if(type == 1) {
            int v;
            cin >> v;
            seg.upd(l, r, v);
        }else {
            cout << seg.query(l,r) << '\n';
        }
    }
}