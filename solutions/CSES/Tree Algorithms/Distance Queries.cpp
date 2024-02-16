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

int n, q;
vector<vector<int>> adjacencies, up;
vector<int> depth;

void dfs(int node, int parent, int currDepth) {
    depth[node] = currDepth;
    up[0][node] = parent;

    for(int adj : adjacencies[node]) {
        if(adj == parent) continue;
        dfs(adj, node, currDepth+1);
    }
}

void computeUps() {
    for(int i = 1; i < int(log2(n))+1; i++) {
        for(int u = 1; u <= n; u++) {
            up[i][u] = up[i-1][up[i-1][u]];
        }
    }
}

int lca(int u, int v) {
    if(depth[u] > depth[v]) swap(u,v);
    int diff = depth[v] - depth[u];
    for(int i = 0; i < 32; i++) {
        if(diff&(1 << i)) {
            v = up[i][v];
        }
    }

    if(u == v) return u;

    for(int i = log2(n); i >= 0; i--) {
        if(up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    }

    return up[0][u];
}

int main() {
    fastio;

    cin >> n >> q;

    adjacencies.resize(n+1);

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }

    depth.resize(n+1);
    up.resize(int(log2(n))+1, vector<int>(n+1));

    dfs(1, -1, 0);

    computeUps();

    while(q--) {
        int u, v;
        cin >> u >> v;

        cout << depth[u] + depth[v] - 2*depth[lca(u,v)] << '\n';
    }
}