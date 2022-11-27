#include "bits/stdc++.h"

using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pli = pair<ll,int>;

int main() {
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adjacencies(n+1);

    for(int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        adjacencies[a].emplace_back(b,c);
    }

    vector<ll> dist(n+1, LONG_LONG_MAX);
    vector<bool> vis(n+1, false);
    priority_queue<pli, vector<pli>, greater<pli>> prioq;

    prioq.emplace(0, 1);
    dist[1] = 0;

    while(!prioq.empty()) {
        int c = prioq.top().second;
        ll cdist = prioq.top().first;
        prioq.pop();

        if(vis[c]) continue;
        vis[c] = true;

        for(pii dest : adjacencies[c]) {
            int adj = dest.first;
            int edge = dest.second;

            if(!vis[adj] && cdist + edge < dist[adj]) {
                dist[adj] = cdist + edge;
                prioq.emplace(cdist + edge, adj);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << dist[i];
        if(i != n) cout << ' ';
        else cout << '\n';
    }
}
