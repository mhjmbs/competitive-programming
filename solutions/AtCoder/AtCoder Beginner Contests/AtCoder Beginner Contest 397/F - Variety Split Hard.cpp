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
    vector<int> lazy;
    int leafs_begin;
    int leafs_count;

    SegmentTree(int n) : leafs_count{1} {
        while(leafs_count < n) leafs_count *= 2;
        seg.resize(2*leafs_count-1, {-1e9,-1});
        lazy.resize(seg.size(), 0);
        leafs_begin = seg.size()-leafs_count;
        
        for(int i = 0; i < n; i++) {
            seg[leafs_begin+i] = {-1e9,i};
        }

        for(int i = leafs_begin-1; i >= 0; i--) {
            seg[i] = max(seg[2*i+1], seg[2*i+2]);
        }
    }

    void unlazy(int i) {
        seg[i].first += lazy[i];
        if(i < leafs_begin) {
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }

    void upd(int l, int r, int val) {
        upd(l, r, 0, leafs_count-1, 0, val);
    }

    void upd(int l, int r, int lx, int rx, int i, int val) {
        unlazy(i);
        if(rx < l || r < lx) return;
        if(l <= lx && rx <= r) {
            lazy[i] += val;
            unlazy(i);
        }else {
            int mid = (lx+rx)/2;
            upd(l, r, lx, mid, 2*i+1, val);
            upd(l, r, mid+1, rx, 2*i+2, val);
            seg[i] = max(seg[2*i+1], seg[2*i+2]);
        }
    }

    pii query(int l, int r) {
        return query(l, r, 0, leafs_count-1, 0);
    }

    pii query(int l, int r, int lx, int rx, int i) {
        unlazy(i);
        if(rx < l || r < lx) return {-1e9,-1};
        if(l <= lx && rx <= r) return seg[i];
        int mid = (lx+rx)/2;
        return max(query(l, r, lx, mid, 2*i+1), query(l, r, mid+1, rx, 2*i+2));
    }
};

int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> a(n);
    for(int& ai : a) cin >> ai;

    vector<map<int,int>> freq(3);
    vector<int> first(n+1,-1), last(n+1, -1);
    
    for(int i = 0; i < n; i++) {
        freq[2][a[i]]++;
    }

    int ans = freq[0].size() + freq[1].size() + freq[2].size();
    int r0 = -1;
    SegmentTree seg(n);

    for(int r1 = 0; r1 < n-1; r1++) {
        freq[1][a[r1]]++;
        freq[2][a[r1]]--;
        if(freq[2][a[r1]] == 0) freq[2].erase(a[r1]);

        if(r1 != 0) {
            seg.upd(r1,r1, seg.query(r1-1,r1-1).first);
        }

        if(first[a[r1]] != -1) {
            seg.upd(r1,r1,1e9-1);
        }else {
            seg.upd(r1,r1,1e9);
            first[a[r1]] = r1;
        }

        if(last[a[r1]] != -1) {
            seg.upd(last[a[r1]],r1,+1);
        }

        last[a[r1]] = r1;

        pii best = seg.query(r0+1,r1);

        if(best.first >= 0) {
            seg.upd(best.second+1,r1, -best.first);
            while(r0 < best.second) {
                r0++;
                freq[0][a[r0]]++;
                freq[1][a[r0]]--;
                if(freq[1][a[r0]] == 0) freq[1].erase(a[r0]);
                if(last[a[r0]] == r0) last[a[r0]] = -1;
            }
        }

        ans = max(ans, int(freq[0].size() + freq[1].size() + freq[2].size()));
    }

    cout << ans << '\n';
}