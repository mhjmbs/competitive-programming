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

int n, k;
ll ans = 0;
vector<vector<int>> g;
vector<int> c, vis;

void dfs(int u, int p) {
    c[u] = 1;
    for(int v : g[u]) {
        if(v == p || vis[v]) continue;
        dfs(v, u);
        c[u] += c[v];
    }
}

int dfs2(int u, int n) {
    for(int v : g[u]) {
        if(vis[v]) continue;
        if(c[v] > n/2) {
            c[u] -= c[v];
            c[v] += c[u];
            return dfs2(v, n);
        }
    }
    return u;
}

void dfs3(int u, int p, int d, vector<int>& paths) {
    paths[d]++;
    for(int v : g[u]) {
        if(v == p || vis[v]) continue;
        dfs3(v, u, d+1, paths);
    }
}

void solve(int u, int p) {
    dfs(u, -1);
    int centroid = dfs2(u, c[u]);
    vis[centroid] = true;
    
    vector<int> paths(c[centroid]);
    paths[0] = 1;
    
    for(int v : g[centroid]) {
        if(!vis[v]) {
            vector<int> nx_paths(c[v]);
            dfs3(v, -1, 0, nx_paths);
            for(int i = 0; i < nx_paths.size(); i++) if(0 <= k-i-1 && k-i-1 < paths.size()) ans += ll(nx_paths[i]) * paths[k-i-1];
            for(int i = 0; i < nx_paths.size(); i++) paths[i+1] += nx_paths[i];
        }
    }

    for(int v : g[centroid]) if(!vis[v]) solve(v, centroid);
}

int main() {
    fastio;

    cin >> n >> k;
    g.resize(n+1);

    for(int m = 0; m < n-1; m++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    c.resize(n+1);
    vis.resize(n+1);
    solve(1, -1);

    cout << ans << '\n';
}