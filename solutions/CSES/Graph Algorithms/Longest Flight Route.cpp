#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

int n, m;
vector<vector<int>> adjacencies;
vector<bool> vis;
vector<int> dist_from_n, nxt;

void dfs(int node) {
    vis[node] = true;
    if(node == n) return;

    for(int adj : adjacencies[node]) {
        if(!vis[adj]) dfs(adj);
        if(dist_from_n[node] < dist_from_n[adj]+1) {
            dist_from_n[node] = dist_from_n[adj]+1;
            nxt[node] = adj;
        }
    }
}

int main() {
    fastio;

    cin >> n >> m;

    adjacencies.resize(n+1);
    vis.resize(n+1, false);
    dist_from_n.resize(n+1, INT_MIN);
    nxt.resize(n+1, -1);

    dist_from_n[n] = 0;

    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adjacencies[u].push_back(v);
    }

    dfs(1);

    if(dist_from_n[1] > 0) { 
        cout << dist_from_n[1]+1 << '\n';
        for(int node = 1; node != -1; node = nxt[node]) {
            cout << node;
            if(node != n) cout << ' ';
            else cout << '\n';
        }
    }else {
        cout << "IMPOSSIBLE\n";
    }
}