#include "bits/stdc++.h"

using namespace std;

    int n, m;
    bool printed = false;
    vector<bool> vis;
    vector<vector<int>> adjacencies;
    stack<int> s;

    void dfs(int node, int father) {
        vis[node] = true;
        s.push(node);

        for(int adj : adjacencies[node]) {
            if(adj == father) continue;
            if(!vis[adj]) {
                dfs(adj, node);
            }else {
                if(!printed) {
                    printed = true;
                    
                    vector<int> path = {adj};
                    int v;

                    do {
                        v = s.top();
                        s.pop();
                        path.push_back(v);
                    }while(v != adj);

                    cout << path.size() << '\n';
                    for(int i = 0; i < path.size(); i++) {
                        cout << path[i];
                        if(i+1 == path.size()) cout << '\n';
                        else cout << ' ';
                    }
                }
            }
        }

        if(s.size() > 0) s.pop();
    }

int main() {
    ios::sync_with_stdio(0);
    
    cin >> n >> m;
    
    adjacencies.resize(n+1);
    vis.resize(n+1, false);

    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs(i, 0);
    }

    if(!printed) cout << "IMPOSSIBLE\n";
}
