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
vector<vector<int>> c, jump;
vector<int> p, level;

void dfs(int node, int prev, int count) {
    level[node] = count;
    for(int adj : c[node]) {
        if(adj == prev) continue;
        dfs(adj, node, count+1);
    }
}

void computeJumps() {
    for(int u = 1; u <= n; u++) {
        jump[0][u] = p[u];
    }

    for(int i = 1; i < 32; i++) {
        for(int u = 1; u <= n; u++) {
            jump[i][u] = jump[i-1][jump[i-1][u]];
        }
    }
}

int lca(int u, int v) {
    if(level[u] > level[v]) swap(u, v);
    int diff = level[v] - level[u];

    for(int i = 0; i < 32; i++) {
        if(diff & (1<<i)) v = jump[i][v]; 
    }

    if(u == v) return u;

    for(int i = 31; i >= 0; i--) {
        if(jump[i][u] != jump[i][v]) {
            u = jump[i][u];
            v = jump[i][v];
        }
    }

    return p[u];
}

int main() {
    fastio;

    cin >> n >> q;

    c.resize(n+1);
    p.resize(n+1);
    level.resize(n+1);
    jump.resize(32, vector<int>(n+1, -1));

    for(int u = 2; u <= n; u++) {
        int v;
        cin >> v;
        p[u] = v;
        c[v].push_back(u);
    }

    dfs(1, -1, 0);
    computeJumps();

    while(q--) {
        int u, v;
        cin >> u >> v;

        cout << lca(u, v) << '\n';
    }
}