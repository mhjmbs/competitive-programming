#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int n, m;
vector<vector<int>> adjacencies;

pii find_most_distant(int node) {
    vector<bool> vis(n+1);

    queue<pii> q;
    q.emplace(node, 0);
    vis[node] = true;

    pii mostDistant = {node, 0};

    while(!q.empty()) {
        int curr = q.front().first;
        int d = q.front().second;
        q.pop();

        if(d > mostDistant.second)
            mostDistant = {curr, d};

        for(int adj : adjacencies[curr]) {
            if(!vis[adj]) {
                q.emplace(adj, d+1);
                vis[adj] = true;
            }
        }
    }

    return mostDistant;
}

int main() {
    fastio;

    cin >> n;

    adjacencies.resize(n+1);

    for(int i = 0, a, b; i < n-1; i++) {
        cin >> a >> b;
        adjacencies[a].push_back(b);
        adjacencies[b].push_back(a);
    }

    pii mostDistant;
    mostDistant = find_most_distant(1);
    mostDistant = find_most_distant(mostDistant.first);

    cout << mostDistant.second << '\n';
}