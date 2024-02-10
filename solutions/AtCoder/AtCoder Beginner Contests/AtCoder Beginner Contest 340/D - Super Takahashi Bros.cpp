#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;



int main() {
    fastio;

    int n;
    cin >> n;

    vector<vector<pll>> adjacencies(n+1);

    for(int i = 1; i < n; i++) {
        int ai, bi, xi;
        cin >> ai >> bi >> xi; 
        adjacencies[i].emplace_back(i+1, ai);
        adjacencies[i].emplace_back(xi, bi);
    }

    vector<ll> dist(n+1, 1e15);
    priority_queue<pll, vector<pll>, greater<pll>> prioq;
    vector<bool> vis(n+1, false);
    dist[1] = 0;
    prioq.emplace(0, 1);

    while(!prioq.empty()) {
        auto [d, node] = prioq.top();
        prioq.pop();

        if(vis[node]) continue;
        vis[node] = true;

        for(auto [adj, cost] : adjacencies[node]) {
            if(d+cost < dist[adj] && !vis[adj]) {
                dist[adj] = d+cost;
                prioq.emplace(d+cost, adj);
            }
        }
    }

    cout << dist[n] << '\n';
}