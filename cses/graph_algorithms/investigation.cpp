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

    vector<vector<pii>> adjacencies(n+1);
    for(int i = 0, u, v, c; i < m; i++) {
        cin >> u >> v >> c;
        adjacencies[u].emplace_back(v,c);
    }

    vector<ll> dist(n+1, LONG_LONG_MAX), ways(n+1, 0);
    vector<int> min_flights(n+1, INT_MAX), max_flights(n+1, INT_MIN);
    priority_queue<pll, vector<pll>, greater<pll>> prioq;
    vector<bool> vis(n+1, false);
    
    prioq.emplace(0 ,1);
    dist[1] = 0;
    ways[1] = 1;
    min_flights[1] = max_flights[1] = 0;

    while(!prioq.empty()) {
        ll c_dist, node;
        tie(c_dist, node) = prioq.top();
        prioq.pop();

        if(vis[node]) continue;
        vis[node] = true;

        for(pii edge : adjacencies[node]) {
            int adj, cost;
            tie(adj, cost) = edge;

            if(!vis[adj] && dist[node] + cost < dist[adj]) {
                dist[adj] = dist[node] + cost;
                ways[adj] = ways[node];
                min_flights[adj] = min_flights[node] + 1;
                max_flights[adj] = max_flights[node] + 1;
                prioq.emplace(dist[adj], adj);
            }else if(dist[node] + cost == dist[adj]) {
                ways[adj] += ways[node];
                ways[adj] %= int(1e9)+7;
                min_flights[adj] = min(min_flights[adj], min_flights[node] + 1);
                max_flights[adj] = max(max_flights[adj], max_flights[node] + 1);
            }
        }
    }

    cout << dist[n] << ' ' << ways[n] << ' ' << min_flights[n] << ' ' << max_flights[n] << '\n';  
}