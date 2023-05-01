#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

vector<vector<int>> adjacencies;

int main() {
    fastio;

    int n;
    cin >> n;

    adjacencies.resize(n+1);

    for(int i = 0, u, v; i < n-1; i++) {
        cin >> u >> v;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }

    if(n <= 3 || all_of(adjacencies.begin()+1, adjacencies.end(), [n](vector<int> &adj) {return adj.size() == 1 || adj.size() == n-1;})) {
        cout << "NO\n";
        return 0;
    }

    int leaf = -1;

    for(int i = 1; i <= n; i++) {
        if(adjacencies[i].size() == 1) {
            leaf = i;
            break;
        }
    }

    queue<int> q;
    vector<bool> vis(n+1, false);
    vector<int> ans;

    q.push(leaf);
    vis[leaf] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(int adj : adjacencies[node]) {
            if(!vis[adj]) {
                vis[adj] = true;
                q.push(adj);
            }
        }
    }

    swap(ans[0],ans[1]);

    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        cout << ans[i];
        if(i != n-1) cout << ' ';
        else cout << '\n';
    }
}