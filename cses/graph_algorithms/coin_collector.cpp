#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

vector<vector<int>> adjacencies, inv_adjacencies;
vector<set<int>> sccs, scc_adjacencies;
vector<int> coins, scc_in_degree, scc;
vector<ll> scc_coins;
vector<bool> vis1, vis2;
stack<int> s;
int curr_scc = 0;

void dfs1(int node) {
    vis1[node] = true;
    for(int adj : adjacencies[node]) {
        if(!vis1[adj]) dfs1(adj);
    }
    s.push(node);
}

void dfs2(int node) {
    vis2[node] = true;

    scc[node] = curr_scc;
    sccs.back().insert(node);
    scc_coins.back() += coins[node];

    for(int adj : inv_adjacencies[node]) {
        if(!vis2[adj]) dfs2(adj);
    }
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    adjacencies.resize(n+1);
    inv_adjacencies.resize(n+1);
    coins.resize(n+1);
    vis1.resize(n+1, false);
    vis2.resize(n+1, false);
    scc.resize(n+1, 0);
    
    for(int i = 1; i <= n; i++) cin >> coins[i];

    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adjacencies[u].push_back(v);
        inv_adjacencies[v].push_back(u);
    }

    for(int node = 1; node <= n; node++) {
        if(!vis1[node]) dfs1(node);
    }

    while(!s.empty()) {
        int node = s.top();
        s.pop();
        if(!vis2[node]) {
            sccs.push_back(set<int>());
            scc_coins.push_back(0);
            dfs2(node);
            ++curr_scc;
        }
    }
    
    scc_adjacencies.resize(sccs.size());
    scc_in_degree.resize(sccs.size(), 0);

    for(int i = 0; i < sccs.size(); i++) {
        for(int node : sccs[i]) {
            for(int adj : adjacencies[node]) {
                if(scc[node] != scc[adj] && scc_adjacencies[scc[node]].count(scc[adj]) == 0) {
                    scc_adjacencies[scc[node]].insert(scc[adj]);
                    scc_in_degree[scc[adj]]++;
                }
            }
        }
    }

    queue<int> q;

    vector<ll> dp(sccs.size(), 0);

    for(int i = 0; i < sccs.size(); i++) {
        if(scc_in_degree[i] == 0) {
            q.push(i);
            dp[i] = scc_coins[i];
        }
    }

    ll ans = 0;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        ans = max(ans, dp[curr]);

        for(int adj : scc_adjacencies[curr]) {
            dp[adj] = max(dp[adj], dp[curr] + scc_coins[adj]);
            scc_in_degree[adj]--;
            if(scc_in_degree[adj] == 0) q.push(adj);
        }
    }

    cout << ans << '\n';
}