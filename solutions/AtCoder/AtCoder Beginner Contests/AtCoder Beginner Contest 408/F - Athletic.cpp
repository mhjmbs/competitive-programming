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
    vector<pii> seg;
    int lf, lct;

    SegmentTree(int n) : lct{1} {
        while(lct < n) lct *= 2;
        seg.resize(2*lct - 1, {-1e9,-1});
        lf = seg.size()-lct;
    }
    
    SegmentTree(vector<int>& v) : SegmentTree(v.size()) {
        for(int i = 0; i < lct; i++) {
            seg[lf+i] = {v[i], i};
        }
        for(int i = lf-1; i >= 0; i--) {
            seg[i] = max(seg[2*i+1],seg[2*i+2]);
        }
    }

    void upd(int i, int val) {
        i += lf;
        seg[i] = {val, i};
        while(i > 0) {
            i = (i-1)/2;
            seg[i] = max(seg[2*i+1],seg[2*i+2]);
        }
    }

    pii query(int l, int r) {
        return query(l, r, 0, lct-1, 0);
    }

    pii query(int l, int r, int lx, int rx, int i) {
        if(r < lx || rx < l) return {-1e9, -1};
        if(l <= lx && rx <= r) return seg[i];
        int mid = (lx+rx)/2;
        return max(query(l, r, lx, mid, 2*i+1),query(l, r, mid+1, rx, 2*i+2));
    }
};

int main() {
    fastio;

    int N, D, R;
    cin >> N >> D >> R;

    vector<int> h(N), pos(N+1);
    for(int i = 0; i < N; i++) {
        cin >> h[i];
        pos[h[i]] = i;
    }

    SegmentTree seg(N);
    vector<int> moves(N, 0);

    for(int hi = 1; hi <= N; hi++) {
        if(hi-D >= 1) seg.upd(pos[hi-D], moves[pos[hi-D]]);
        auto [ml, l] = seg.query(max(pos[hi]-R, 0),pos[hi]-1);
        auto [mr, r] = seg.query(pos[hi]+1,min(pos[hi]+R, N-1));
        moves[pos[hi]] = max({moves[pos[hi]], ml+1, mr+1});
    }
    
    cout << *max_element(moves.begin(), moves.end()) << '\n';
}