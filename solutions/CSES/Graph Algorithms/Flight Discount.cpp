#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

void dijkstra(int start, vector<vector<pii>> &adjacencies, vector<ll> &dist) {
    dist[start] = 0;

    vector<int> vis(adjacencies.size(), false);
    priority_queue<pll, vector<pll>, greater<pll>> prioq;
    prioq.emplace(0, start);

    while(!prioq.empty()) {
        ll curr, curr_dist;
        tie(curr_dist, curr) = prioq.top();
        prioq.pop();

        if(vis[curr]) continue;
        vis[curr] = true;

        for(pii edge : adjacencies[curr]) {
            int adj, cost;
            tie(adj, cost) = edge;

            if(!vis[adj] && dist[curr] + cost < dist[adj]) {
                dist[adj] = dist[curr] + cost;
                prioq.emplace(dist[curr] + cost, adj);
            }
        }
    }
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adjacencies(n+1), inv_adjacencies(n+1);

    for(int i = 0, u, v, c; i < m; i++) {
        cin >> u >> v >> c;
        adjacencies[u].emplace_back(v,c);
        inv_adjacencies[v].emplace_back(u,c);
    }

    vector<ll> dist_from_1(n+1, ll(1e17)), dist_to_n(n+1, ll(1e17));

    dijkstra(1, adjacencies, dist_from_1);
    dijkstra(n, inv_adjacencies, dist_to_n);

    ll ans = dist_from_1[n]; 

    for(int i = 1; i <= n; i++) {
        for(pii edge : adjacencies[i]) {
            int adj, cost;
            tie(adj, cost) = edge;
            int d = cost/2;
            ans = min(ans, dist_from_1[i] + d + dist_to_n[adj]);
        }
    }

    cout << ans << '\n';
}