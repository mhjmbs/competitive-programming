#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
#define endl '\n'

int n, m;
vector<vector<int>> g;
int ans = 0;
vector<int> vis, reached;

void dfs(int u) {
    vis[u] = true;

    if(u == n) {
        ans++;
        reached[u] = true;
        return;
    }

    for(int v : g[u]) {
        if(!vis[v]) dfs(v);
        else if(reached[v]) ans++;
        reached[u] |= reached[v];
    }
}


signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    cin >> n >> m;
    g.resize(n+1);
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    vis.resize(n+1);
    reached.resize(n+1);

    dfs(1);

    cout << ans << '\n';

    return 0;
}