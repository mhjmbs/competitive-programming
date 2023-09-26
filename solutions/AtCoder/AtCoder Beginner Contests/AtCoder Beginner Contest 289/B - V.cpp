#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

vector<vector<int>> adjacencies;
priority_queue<int> comp;
vector<bool> vis;

void dfs(int node) {
    vis[node] = true;

    comp.push(node);

    for(int adj : adjacencies[node]) {
        if(!vis[adj]) {
            dfs(adj);
        }
    }
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    adjacencies.resize(n+1);
    vis.resize(n+1, false);

    for(int i = 0, ai; i < m; i++) {
        cin >> ai;
        adjacencies[ai].push_back(ai+1);
    }

    int print_counter = 0;

    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        dfs(i);
        while(!comp.empty()) {
            cout << comp.top();
            print_counter++;
            comp.pop();

            if(print_counter < n) cout << ' ';
            else cout << '\n';
        }
    }
}