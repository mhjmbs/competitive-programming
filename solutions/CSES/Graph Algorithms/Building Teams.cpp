#include "bits/stdc++.h"

using namespace std;

int n, m;
bool possible = true;
vector<vector<int>> adjacencies;
vector<bool> vis;
vector<int> team;

void dfs(int node, int currTeam) {
    vis[node] = true;
    team[node] = currTeam;
    int nxtTeam = currTeam == 1 ? 2 : 1;

    for(int adj : adjacencies[node]) {
        if(!vis[adj]) {
            dfs(adj, nxtTeam);
        }

        if(team[adj] == team[node]) {
            possible = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);

    cin >> n >> m;

    adjacencies.resize(n+1);
    vis.resize(n+1);
    team.resize(n+1);

    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        adjacencies[a].push_back(b);
        adjacencies[b].push_back(a);
    }
    
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i, 1);
        }
    }

    if(possible) {
        for(int i = 1; i <= n; i++) {
            cout << team[i];
            if(i != n) cout << ' ';
            else cout << '\n';
        }
    }else {
        cout << "IMPOSSIBLE\n";
    }
}
