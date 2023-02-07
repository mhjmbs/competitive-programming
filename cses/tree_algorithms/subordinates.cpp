#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

vector<vector<int>> adjacencies;
vector<int> subordinates;

void dfs(int node, int parent) {
    for(int adj : adjacencies[node]) {
        if(adj == parent) continue;
        dfs(adj, node);
        subordinates[node] += subordinates[adj] + 1;
    }
}

int main() {
    fastio;

    int n;
    cin >> n;

    adjacencies.resize(n+1);
    subordinates.resize(n+1, 0);

    for(int i = 2, p; i <= n; i++) {
        cin >> p;
        adjacencies[p].push_back(i);
    }

    dfs(1, 1);

    for(int i = 1; i <= n; i++) {
        cout << subordinates[i];
        if(i != n) cout << ' ';
        else cout << '\n';
    }
}