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

struct SegmentTree {
    vector<pll> seg;
    vector<ll> lazy;
    int leafsCount, leafsBegin;

    SegmentTree(const vector<ll>& v) : leafsCount{1} {
        while(leafsCount < v.size()) leafsCount <<= 2;
        seg.resize(2*leafsCount-1, {-1e16,-1});
        lazy.resize(seg.size(), 0);
        leafsBegin = seg.size() - leafsCount;

        for(int i = 0; i < v.size(); i++) {
            seg[leafsBegin+i] = {v[i],i};
        }
        for(int i = leafsBegin-1; i >= 0; i--) {
            seg[i] = max(seg[2*i+1], seg[2*i+2]);
        }
    }

    void unlazy(int i) {
        seg[i].first += lazy[i];
        if(i < leafsBegin) {
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }

    void update(int l, int r, ll val) {
        update(l, r, 0, leafsCount-1, 0, val);
    }

    void update(int l, int r, int lx, int rx, int i, ll val) {
        unlazy(i);
        if(r < lx || rx < l) return;
        if(l <= lx && rx <= r) {
            lazy[i] += val;
            return;
        }
        int mid = (lx+rx)/2;
        update(l, r, lx, mid, 2*i+1, val), update(l, r, mid+1, rx, 2*i+2, val);
        unlazy(2*i+1),unlazy(2*i+2);
        seg[i] = max(seg[2*i+1], seg[2*i+2]);
    }

    pll query(int l, int r) {
        return query(l, r, 0, leafsCount-1, 0);
    }
    
    pll query(int l, int r, int lx, int rx, int i) {
        unlazy(i);
        if(r < lx || rx < l) return {-1e16,-1};
        if(l <= lx && rx <= r) return seg[i];
        int mid = (lx+rx)/2;
        return max(query(l, r, lx, mid, 2*i+1), query(l, r, mid+1, rx, 2*i+2));
    }
};

struct SegmentTree2 {
    vector<pll> seg;
    vector<ll> lazy;
    int leafsCount, leafsBegin;

    SegmentTree2(const vector<ll>& v) : leafsCount{1} {
        while(leafsCount < v.size()) leafsCount <<= 2;
        seg.resize(2*leafsCount-1, {1e16,-1});
        lazy.resize(seg.size(), 0);
        leafsBegin = seg.size() - leafsCount;

        for(int i = 0; i < v.size(); i++) {
            seg[leafsBegin+i] = {v[i],i};
        }
        for(int i = leafsBegin-1; i >= 0; i--) {
            seg[i] = min(seg[2*i+1], seg[2*i+2]);
        }
    }

    void unlazy(int i) {
        seg[i].first += lazy[i];
        if(i < leafsBegin) {
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }

    void update(int l, int r, ll val) {
        update(l, r, 0, leafsCount-1, 0, val);
    }

    void update(int l, int r, int lx, int rx, int i, ll val) {
        unlazy(i);
        if(r < lx || rx < l) return;
        if(l <= lx && rx <= r) {
            lazy[i] += val;
            return;
        }
        int mid = (lx+rx)/2;
        update(l, r, lx, mid, 2*i+1, val), update(l, r, mid+1, rx, 2*i+2, val);
        unlazy(2*i+1),unlazy(2*i+2);
        seg[i] = min(seg[2*i+1], seg[2*i+2]);
    }

    pll query(int l, int r) {
        return query(l, r, 0, leafsCount-1, 0);
    }
    
    pll query(int l, int r, int lx, int rx, int i) {
        unlazy(i);
        if(r < lx || rx < l) return {1e16,-1};
        if(l <= lx && rx <= r) return seg[i];
        int mid = (lx+rx)/2;
        return min(query(l, r, lx, mid, 2*i+1), query(l, r, mid+1, rx, 2*i+2));
    }
};

int main(){
    ios_base::sync_with_stdio(0), cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    vector<ll> v(n), c(n), p(n);
    for(ll& vi : v) cin >> vi;
    for(ll& ci : c) cin >> ci;
    for(ll& pi : p) cin >> pi;

    SegmentTree profit(v);
    SegmentTree2 lim(c);

    ll sold = 0, ans = 0;

    auto[L, pos] = lim.query(0, n-1);
    while(L == 0) {
        profit.update(pos,n-1,-p[pos]);
        lim.update(pos, pos, 1e16);
        tie(L, pos) = lim.query(0, n-1);
    }

    while(sold < k) {
        pll best = profit.query(0, n-1);
        if(best.first <= 0) break;

        tie(L, pos) = lim.query(0, best.second);
        ll sales = min(L, k-sold);
        ans += best.first * sales;
        sold += sales;

        lim.update(0, best.second, -sales);

        auto[L, pos] = lim.query(0, best.second);
        while(L == 0) {
            profit.update(pos,n-1,-p[pos]);
            lim.update(pos, pos, 1e16);
            tie(L, pos) = lim.query(0, best.second);
        }
    }

    cout << ans << '\n';

    return 0;
}