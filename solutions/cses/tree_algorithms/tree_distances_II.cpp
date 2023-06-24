#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

int n;
vector<vector<int>> adjacencies;
vector<bool> vis;
vector<ll> sum_dist_subtree, size_subtree, sum_dist;

void init(int node) {
    vis[node] = true;

    size_subtree[node] = 1;

    for(int adj : adjacencies[node]) {
        if(!vis[adj]) {
            init(adj);
            size_subtree[node] += size_subtree[adj];
            sum_dist_subtree[node] += sum_dist_subtree[adj] + size_subtree[adj]; 
        }
    }
}

void solve(int node) {
    vis[node] = true;

    for(int adj : adjacencies[node]) {
        if(!vis[adj]) {
            sum_dist[adj] = sum_dist_subtree[adj] + sum_dist[node] - (sum_dist_subtree[adj] + size_subtree[adj]) + (n-size_subtree[adj]);
            solve(adj);
        }
    }
}

int main () {
    fastio;

    cin >> n;

    adjacencies.resize(n+1);
    for(int i = 0, u, v; i < n-1; i++) {
        cin >> u >> v;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }

    vis.resize(n+1, false);
    sum_dist_subtree.resize(n+1, 0);
    size_subtree.resize(n+1, 0);
    sum_dist.resize(n+1, 0);

    init(1);

    sum_dist[1] = sum_dist_subtree[1];
    fill(vis.begin(), vis.end(), false);
    solve(1);

    for(int i = 1; i <= n; i++) {
        cout << sum_dist[i];
        if(i != n) cout << ' ';
        else cout << '\n';
    }
}