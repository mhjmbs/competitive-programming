#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

void compute_parents(int node, vector<vector<int>> &adjacencies, vector<int> &parent) {
    for(int adj : adjacencies[node]) {
        if(adj != parent[node]) {
            parent[adj] = node;
            compute_parents(adj, adjacencies, parent);
        }
    }
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> c(n);
        for(int &x : c) {
            cin >> x;
            x--;
        }

        vector<vector<int>> adjacencies(n);

        for(int i = 0, u, v; i < n-1; i++) {
            cin >> u >> v;
            u--;v--;
            adjacencies[u].push_back(v);
            adjacencies[v].push_back(u);
        }

        vector<int> parent(n);
        parent[c[0]] = -1;
        compute_parents(c[0], adjacencies, parent);

        int ans = n;
        vector<int> minDist(n, n);

        for(int i = 0; i < n; i++) {
            int v = c[i], val = 0;
            while(v != -1 && val < ans) {
                ans = min(ans, minDist[v] + val);
                minDist[v] = min(val, minDist[v]);
                v = parent[v];
                val++;
            }

            if(i != 0) {
                cout << ans;
                if(i != n-1) cout << ' ';
                else cout << '\n';
            }
        }


    }
}