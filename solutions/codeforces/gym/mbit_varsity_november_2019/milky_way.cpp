#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

int main() {
    fastio;

    int n, m, c;
    cin >> n >> m >> c;

    int a, b;
    cin >> a >> b;

    vector<int> p(n+1);
    for(int i = 1; i <= n; i++) cin >> p[i];

    vector<vector<pii>> adjacencies(n+1);
    for(int i = 0, u, v, f; i < m; i++) {
        cin >> u >> v >> f;
        adjacencies[u].emplace_back(v,f);
        adjacencies[v].emplace_back(u,f);
    }

    vector<int> vis(n+1, -1);
    queue<tiii> q;
    q.emplace(a, 0, 0); //node, days, fuel

    int ans = -1;

    while(!q.empty()) {
        int node, days, fuel;
        tie(node, days, fuel) = q.front();
        q.pop();

        if(node == b) {
            ans = days;
            break;
        }

        if(fuel < c) {
            if(fuel + p[node] <= c) {
                q.emplace(node, days+1, fuel + p[node]);
                vis[node] = fuel+p[node];
            }else {
                q.emplace(node, days+1, c);
                vis[node] = c;
            }
        }

        for(pii edge : adjacencies[node]) {
            int adj, cost;
            tie(adj, cost) = edge;
            if(fuel >= cost && vis[adj] < fuel - cost) {
                q.emplace(adj, days+1, fuel-cost);
                vis[adj] = fuel-cost;
            }
        }
    }

    cout << ans << '\n';
}