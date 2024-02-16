#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

int n, m;
vector<int> t, tin, tout, eulerTour, depth;
vector<vector<int>> adjacencies, up;

struct SegmentTree {
    vector<map<int,int>> seg;
    int leafsBegin;
    int leafsCount;

    SegmentTree(int n) {
        leafsCount = 1;
        while(leafsCount < n) leafsCount *= 2;
        seg.resize(2*leafsCount-1);
        leafsBegin = seg.size() - leafsCount;
    }

    SegmentTree(vector<pii>& v) : SegmentTree(v.size()) {
        for(int i = 0; i < v.size(); i++) {
            seg[leafsBegin+i][v[i].first] += v[i].second;
        }
        for(int i = leafsBegin-1; i >= 0; i--) {
            seg[i] = merge(seg[2*i+1], seg[2*i+2]);
        }
    }

    int query(int l, int r, int ci) {
        return query(l, r, ci, 0, leafsCount-1, 0);
    }

    int query(int l, int r, int ci, int lx, int rx, int i) {
        int mid = (lx+rx)/2;
        if(rx < l || r < lx) return 0;
        if(l <= lx && rx <= r) return seg[i][ci];
        return query(l, r, ci, lx, mid, 2*i+1) + query(l, r, ci, mid+1, rx, 2*i+2);
    }

    map<int,int> merge(const map<int,int>& a, const map<int,int>& b) {
        map<int,int> ans;
        for(auto [val, freq] : a) ans[val] += freq;
        for(auto [val, freq] : b) ans[val] += freq;

        for(auto it = ans.begin(); it != ans.end();) {
            auto curr = it;
            it++;
            if(curr->second == 0) ans.erase(curr);
        }
        
        return ans;
    }
};

void dfs(int u, int p, int d) {
    static int t = 0;
    tin[u] = t++;
    eulerTour[tin[u]] = u;
    depth[u] = d;
    up[0][u] = p;

    for(int adj : adjacencies[u]) {
        if(adj == p) continue;
        dfs(adj, u, d+1);
    }

    tout[u] = t++;
}

int lca(int u, int v) {
    if(depth[u] > depth[v]) swap(u,v);
    int diff = depth[v] - depth[u];
    for(int i = 0; i < up.size(); i++) {
        if(diff&(1<<i)) v = up[i][v];
    }

    if(u == v) return u;

    for(int i = up.size()-1; i >= 0; i--) {
        if(up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    }

    return up[0][u];
}

int main() {
    fastio;

    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");

    cin >> n >> m;

    t.resize(n+1);
    for(int i = 1; i <= n; i++) cin >> t[i];

    adjacencies.resize(n+1);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }

    tin.resize(n+1);
    tout.resize(n+1);
    depth.resize(n+1);
    eulerTour.resize(2*n);
    up.resize(ceil(log2(n)), vector<int>(n+1));

    dfs(1, -1, 0);

    for(int i = 1; i < up.size(); i++) {
        for(int u = 1; u <= n; u++) {
            up[i][u] = up[i-1][up[i-1][u]];
        }
    }

    vector<pii> newT(2*n);
    for(int u = 1; u <= n; u++) {
        newT[tin[u]] = {t[u],1};
        newT[tout[u]] = {t[u],-1};
    }

    SegmentTree seg(newT);

    while(m--) {
        int ai, bi, ci;
        cin >> ai >> bi >> ci;
        int count = seg.query(tin[lca(ai, bi)], tin[ai], ci) + seg.query(tin[lca(ai, bi)], tin[bi], ci) - seg.query(tin[lca(ai,bi)], tin[lca(ai,bi)], ci);
        cout << int(count > 0);
    }
    cout << '\n';
}