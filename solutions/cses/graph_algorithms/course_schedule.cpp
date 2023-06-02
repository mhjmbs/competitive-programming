#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacencies(n+1);
    vector<int> entrance_degree(n+1, 0);
    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adjacencies[u].push_back(v);
        entrance_degree[v]++;
    }

    queue<int> q;

    for(int node = 1; node <= n; node++) {
        if(entrance_degree[node] == 0) q.push(node);
    }

    vector<int> ans;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        ans.push_back(node);
        for(int adj : adjacencies[node]) {
            entrance_degree[adj]--;
            if(entrance_degree[adj] == 0) q.push(adj);
        }
    }

    if(ans.size() == n) {
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i];
            if(i != ans.size()-1) cout << ' ';
            else cout << '\n';
        }
    }else {
        cout << "IMPOSSIBLE\n";
    }
}