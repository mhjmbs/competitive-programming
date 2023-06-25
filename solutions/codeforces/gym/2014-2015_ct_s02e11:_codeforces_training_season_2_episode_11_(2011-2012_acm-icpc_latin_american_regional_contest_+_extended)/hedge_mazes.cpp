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

struct DSU {
    vector<int> rep;
    vector<int> max_depth;

    DSU(int n) {
        rep.resize(n);
        max_depth.resize(n, 0);
        for(int i = 0; i < n; i++) {
            rep[i] = i;
        }
    }

    int find(int u) {
        if(rep[u] == u) return u;
        return rep[u] = find(rep[u]);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);

        if(u == v) return;

        if(max_depth[v] > max_depth[u]) swap(u, v);

        rep[v] = u;
        max_depth[u] = max(max_depth[u], max_depth[v]+1);
    }
};

void dfs(int node, int parent, int &curr_time, vector<int> &lowlink, vector<int> &time, vector<vector<int>> &adjacencies, vector<vector<int>> &bridge_adjacencies) {
    lowlink[node] = time[node] = curr_time;

    for(int adj : adjacencies[node]) {
        if(time[adj] == -1) {
            dfs(adj, node, ++curr_time, lowlink, time, adjacencies, bridge_adjacencies);
        }

        if(adj != parent) {
            lowlink[node] = min(lowlink[node], lowlink[adj]);
        }

        if(time[node] < lowlink[adj]) {
            bridge_adjacencies[node].push_back(adj);
            bridge_adjacencies[adj].push_back(node);
        }
    }
}

void find_bridges(vector<vector<int>> &adjacencies, vector<vector<int>> &bridge_adjacencies) {
    vector<int> time(adjacencies.size(), -1), lowlink(adjacencies.size(), -1);
    int curr_time = 0;

    for(int node = 1; node < adjacencies.size(); node++) {
        if(time[node] == -1) {
            dfs(node, -1, curr_time, lowlink, time, adjacencies, bridge_adjacencies);
        }
    }
}

void dfs_bridges(int node, vector<vector<int>> &bridge_adjacencies, vector<bool> &vis, DSU &bridge_paths) {
    vis[node] = true;

    for(int adj : bridge_adjacencies[node]) {
        if(!vis[adj]) {
            bridge_paths.merge(node, adj);
            dfs_bridges(adj, bridge_adjacencies, vis, bridge_paths);
        }
    }
}

int main() {
    fastio;

    while(true) {
        int r, c, q;
        cin >> r >> c >> q;

        if(r == 0) break;

        vector<vector<int>> adjacencies(r+1);
        for(int i = 0, a, b; i < c; i++) {
            cin >> a >> b;
            adjacencies[a].push_back(b);
            adjacencies[b].push_back(a);
        }

        vector<vector<int>> bridge_adjacencies(r+1);
        find_bridges(adjacencies, bridge_adjacencies);

        DSU bridge_paths(r+1);

        vector<bool> vis(r+1);
        
        for(int node = 1; node <= r; node++) {
            dfs_bridges(node, bridge_adjacencies, vis, bridge_paths);
        }

        while(q--) {
            int s, t;
            cin >> s >> t;

            if(bridge_paths.find(s) == bridge_paths.find(t)) {
                cout << "Y\n";
            }else {
                cout << "N\n";
            }
        }
        
        cout << "-\n";
    }
}