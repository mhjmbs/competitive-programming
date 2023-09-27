#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

vector<vector<int>> adjacencies, inv_adjacencies;
vector<bool> vis1, vis2;
stack<int> s;
vector<int> scc;
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
    vis1.resize(n+1, false);
    vis2.resize(n+1, false);
    scc.resize(n+1, -1);

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
            curr_scc++;
            dfs2(node);
        }
    }

    cout << curr_scc << '\n';

    for(int i = 1; i <= n; i++) {
        cout << scc[i];
        if(i != n) cout << ' ';
        else cout << '\n';
    }
}