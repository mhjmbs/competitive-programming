#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

vector<vector<int>> adjacencies;
vector<int> entrance_degree;
vector<int> vis;
void dfs(int node) {
    vis[node] = true;
    for(int adj : adjacencies[node]) {
        entrance_degree[adj]++;
        if(!vis[adj]) dfs(adj);
    }
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    adjacencies.resize(n+1);
    entrance_degree.resize(n+1, 0);
    vis.resize(n+1, false);

    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adjacencies[u].push_back(v);
    }

    dfs(1);

    vector<int> dp(n+1, 0);
    queue<int> q;

    dp[1] = 1;
    q.push(1);

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int adj : adjacencies[node]) {
            dp[adj] += dp[node];
            dp[adj] %= int(1e9)+7;
            entrance_degree[adj]--;
            if(entrance_degree[adj] == 0) q.push(adj);
        }
    }

    cout << dp[n] << '\n';
}