#include "bits/stdc++.h"

using namespace std;

int n, m;
vector<vector<int>> adjacencies;
vector<bool> vis;

void dfs(int node) {
    vis[node] = true;

    for(int adj : adjacencies[node]) {
        if(!vis[adj]) {
            dfs(adj);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);

    cin >> n >> m;

    adjacencies.resize(n+1);
    vis.resize(n+1);

    for(int i = 0, c1, c2; i < m; i++) {
        cin >> c1 >> c2;
        adjacencies[c1].push_back(c2);
        adjacencies[c2].push_back(c1);
    }

    vector<int> rep;

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            rep.push_back(i);
            dfs(i);
        }
    }

    cout << rep.size()-1 << '\n';

    for(int i = 0; i < rep.size()-1; i++) {
        cout << rep[i] << ' ' << rep[i+1] << '\n';
    }
}
