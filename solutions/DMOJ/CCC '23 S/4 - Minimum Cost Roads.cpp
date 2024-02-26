#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tiiii = tuple<int,int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

int n, m;
vector<vector<tiii>> adjacencies;

ll dijkstra(int u, int v) {
    vector<ll> dist(n+1, 1e15);
    priority_queue<pll, vector<pll>, greater<pll>> prioq;
    vector<int> vis(n+1, false);

    prioq.emplace(0,u);
    dist[u] = 0;

    while(!prioq.empty()) {
        auto[d,curr] = prioq.top();
        prioq.pop();

        for(auto [adj,l,c] : adjacencies[curr]) {
            if(!vis[adj] && dist[curr] + l < dist[adj]) {
                dist[adj] = dist[curr] + l;
                prioq.emplace(dist[adj],adj);
            }
        }

        vis[curr] = true;
    }

    return dist[v];
}

int main() {
    fastio;

    cin >> n >> m;

    priority_queue<tiiii, vector<tiiii>, greater<tiiii>> prioq;

    for(int i = 0; i < m; i++) {
        int u, v, l, c;
        cin >> u >> v >> l >> c;
        prioq.emplace(l,c,u,v);
    }

    adjacencies.resize(n+1);
    ll ans = 0;

    while(!prioq.empty()) {
        auto [l,c,u,v] = prioq.top();
        prioq.pop();

        ll dist = dijkstra(u,v);
        
        adjacencies[u].emplace_back(v,l,c);
        adjacencies[v].emplace_back(u,l,c);
        
        ll newDist = dijkstra(u,v);

        if(dist == newDist) {
            adjacencies[u].pop_back();
            adjacencies[v].pop_back();
        }else {
            ans += c;
        }
    }

    cout << ans << '\n';
}