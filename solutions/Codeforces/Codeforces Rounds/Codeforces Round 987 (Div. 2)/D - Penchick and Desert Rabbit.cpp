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

struct SegmentTree_mx {
    vector<pii> seg;
    int leafsBegin, leafsCount;

    SegmentTree_mx(int n = 0) {
        leafsCount = 1;
        while(leafsCount < n) leafsCount *= 2;
        seg.resize(2*leafsCount-1, {INT_MIN,-1});
        leafsBegin = seg.size() - leafsCount;
    }

    SegmentTree_mx(vector<int>& v) : SegmentTree_mx(v.size()) {
        for(int i = 0; i < v.size(); i++) {
            seg[leafsBegin+i] = {v[i],i};
        }
        for(int i = leafsBegin-1; i >= 0; i--) {
            seg[i] = merge(seg[2*i+1], seg[2*i+2]);
        }
    }

    void upd(int i, int val) {
        i = leafsBegin+i;
        seg[i].first = val;
        while(i > 0) {
            i = (i-1)/2;
            seg[i] = merge(seg[2*i+1], seg[2*i+2]);
        }
    }

    pii query(int l, int r) {
        return query(l, r, 0, leafsCount-1, 0);
    }

    pii query(int l, int r, int lx, int rx, int i) {
        if(rx < l || r < lx) return {INT_MIN,-1};
        if(l <= lx && rx <= r) return seg[i];
        int mid = (lx+rx)/2;
        return merge( query(l,r,lx,mid,2*i+1), query(l,r,mid+1,rx,2*i+2) ); 
    }

    pii merge(pii a, pii b) {
        if(a.first > b.first) return a;
        else if(a.first < b.first) return b;
        else if(a.second < b.second) return a;
        return b;
    }
};

struct SegmentTree_mn {
    vector<pii> seg;
    int leafsBegin, leafsCount;

    SegmentTree_mn(int n = 0) {
        leafsCount = 1;
        while(leafsCount < n) leafsCount *= 2;
        seg.resize(2*leafsCount-1, {INT_MAX,-1});
        leafsBegin = seg.size() - leafsCount;
    }

    SegmentTree_mn(vector<int>& v) : SegmentTree_mn(v.size()) {
        for(int i = 0; i < v.size(); i++) {
            seg[leafsBegin+i] = {v[i],i};
        }
        for(int i = leafsBegin-1; i >= 0; i--) {
            seg[i] = merge(seg[2*i+1], seg[2*i+2]);
        }
    }

    void upd(int i, int val) {
        i = leafsBegin+i;
        seg[i].first = val;
        while(i > 0) {
            i = (i-1)/2;
            seg[i] = merge(seg[2*i+1], seg[2*i+2]);
        }
    }

    pii query(int l, int r) {
        return query(l, r, 0, leafsCount-1, 0);
    }

    pii query(int l, int r, int lx, int rx, int i) {
        if(rx < l || r < lx) return {INT_MAX,-1};
        if(l <= lx && rx <= r) return seg[i];
        int mid = (lx+rx)/2;
        return merge( query(l,r,lx,mid,2*i+1), query(l,r,mid+1,rx,2*i+2) ); 
    }

    pii merge(pii a, pii b) {
        if(a.first < b.first) return a;
        else if(a.first > b.first) return b;
        else if(a.second > b.second) return a;
        return b;
    }
};

int n;
vector<int> a, ans, vis;
vector<vector<int>> pos;
SegmentTree_mx sg_mx;
SegmentTree_mn sg_mn;

void dfs(int pos) {
    vis[pos] = true;
    sg_mx.upd(pos, INT_MIN);
    sg_mn.upd(pos, INT_MAX);

    auto [hi, i] = sg_mx.query(0,pos-1);
    while(hi > a[pos]) {
        ans[i] = max(ans[i], ans[pos]);
        dfs(i);
        tie(hi,i) = sg_mx.query(0,pos-1);
    }

    tie(hi,i) = sg_mn.query(pos+1, n-1);
    while(hi < a[pos]) {
        ans[i] = max(ans[i], ans[pos]);
        dfs(i);
        tie(hi,i) = sg_mn.query(pos+1,n-1);
    }
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        cin >> n;

        a.resize(n);
        for(int& ai : a) cin >> ai;

        sg_mx = SegmentTree_mx(a);
        sg_mn = SegmentTree_mn(a);

        ans = a;
    
        pos.assign(n+1, vector<int>());
        for(int i = 0; i < n; i++) pos[a[i]].push_back(i);

        vis.assign(n, false);

        for(int curr = n; curr >= 1; curr--) {
            for(int pi : pos[curr]) {
                if(!vis[pi]) dfs(pi);
            }
        }

        for(int ans_i : ans) cout << ans_i << ' ';
        cout << '\n';
    }
}