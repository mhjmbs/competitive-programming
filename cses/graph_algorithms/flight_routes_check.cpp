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
vector<vector<int>> sccs;
vector<int> scc;
vector<bool> has_adjacency;

void dfs1(int node) {
    vis1[node] = true;
    for(int adj : adjacencies[node]) {
        if(!vis1[adj]) dfs1(adj);
    }
    s.push(node);
}

void dfs2(int node) {
    vis2[node] = true;
    sccs.back().push_back(node);
    scc[node] = sccs.size()-1;
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
    scc.resize(n+1);

    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adjacencies[u].push_back(v);
        inv_adjacencies[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        if(!vis1[i]) dfs1(i);
    }

    while(!s.empty()) {
        int node = s.top();
        s.pop();
        if(!vis2[node]) {
            sccs.push_back(vector<int>());
            dfs2(node);
        }
    }

    if(sccs.size() == 1) {
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";

    has_adjacency.resize(sccs.size(), false);

    for(int i = 0; i < sccs.size(); i++) {
        for(int node : sccs[i]) {
            for(int adj : adjacencies[node]) {
                if(scc[adj] != scc[node]) has_adjacency[i] = true;
            }
        }
    }

    int ans1 = 0, ans2;

    for(int i = 1; i < sccs.size(); i++) {
        ans2 = i;
        if(!has_adjacency[i]) {
            swap(ans1, ans2);
            break;
        }
    }

    cout << sccs[ans1][0] << ' ' << sccs[ans2][0] << '\n';
}