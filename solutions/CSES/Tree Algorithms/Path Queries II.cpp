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
 
template <typename T>
struct SegmentTree {
    inline static const T neutral = numeric_limits<T>::min();
    vector<T> seg;
    int l0, ln;
 
    SegmentTree() = default;
 
    SegmentTree(const vector<T>& v) {
        ln = 1;
        while(ln < v.size()) ln *= 2;
        seg.resize(2*ln-1, neutral);
        
        l0 = seg.size() - ln;
 
        for(int i = 0; i < v.size(); i++) {
            seg[l0+i] = v[i];
        }
 
        for(int i = l0-1; i >= 0; i--) {
            seg[i] = merge(seg[2*i+1], seg[2*i+2]);
        }
    }
 
    void upd(int i, T val) {
        i = l0 + i;
        seg[i] = val;
        while(i > 0) {
            i = (i-1)/2;
            seg[i] = merge(seg[2*i+1], seg[2*i+2]);
        }
    }
 
    T query(int l, int r) {
        return query(l, r, 0, ln-1, 0);
    }
 
    T query(int l, int r, int lx, int rx, int i) {
        if(rx < l || r < lx) return neutral;
        if(l <= lx && rx <= r) return seg[i];
        int mid = (lx+rx)/2;
        return merge( query(l, r, lx, mid, 2*i+1), query(l, r, mid+1, rx, 2*i+2) );
    }
    
    T merge(T lc, T rc) {
        return max(lc,rc);
    }
};
 
struct HeavyLightDecomposition {
    int n;
    vector<int> hd, p, sz, in;
    SegmentTree<int> hld;
    
    HeavyLightDecomposition(vector<vector<int>>& g, vector<int>& val, int root) : n(g.size()), hd(n,root), p(n,-1), sz(n), in(n) {
        dfs_sz(root, -1, g, val);
        vector<int> new_val(n);
        int t = 0;
        dfs(root, -1, g, val, new_val, t);
        hld = SegmentTree<int>(new_val);
    }
 
    void dfs_sz(int u, int last, vector<vector<int>>& g, vector<int>& val) {
        sz[u] = 1;
        for(int& v : g[u]) {
            if(v == last) continue;
            p[v] = u;
            dfs_sz(v, u, g, val);
            sz[u] += sz[v];
 
            if(g[u][0] == last || sz[v] > sz[g[u][0]]) {
                swap(v, g[u][0]);
            }
        }
    }
 
    void dfs(int u, int last, vector<vector<int>>& g, vector<int>& val, vector<int>& new_val, int& t) {
        in[u] = t++;
        new_val[in[u]] = val[u];
        for(int v : g[u]) {
            if(v == last) continue;
            hd[v] = (v == g[u][0]) ? hd[u] : v; 
            dfs(v, u, g, val, new_val, t);
        }
    }
 
    void upd(int u, int x) {
        hld.upd(in[u], x);
    }
 
    int query(int u, int v) {
        int ans = INT_MIN;
        while(hd[u] != hd[v]) {
            if(in[hd[u]] > in[hd[v]]) swap(u,v);
            ans = max(ans, hld.query(in[hd[v]], in[v]));
            v = p[hd[v]];
        }
        if(in[u] > in[v]) swap(u,v);
        ans = max(ans, hld.query(in[u], in[v]));
        return ans;
    }
};
 
int main() {
    fastio;

    int n, q;
    cin >> n >> q;
 
    vector<int> v(n+1);
    for(int u = 1; u <= n; u++) cin >> v[u];
 
    vector<vector<int>> g(n+1);
    for(int m = 0; m < n-1; m++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    HeavyLightDecomposition hld(g, v, 1);
 
    while(q--) {
        int qi;
        cin >> qi;
 
        if(qi == 1) {
            int u, x;
            cin >> u >> x;
            hld.upd(u, x);
        }else {
            int u, v;
            cin >> u >> v;
            cout << hld.query(u, v) << ' ';
        }
    }
    cout << '\n';
}