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

int ans;
pii edge;

class Dsu {
    vector<int> parent;
    vector<int> height;

    public:

    Dsu(int n) {
        height.resize(n, 0);
        parent.resize(n, -1);
    }

    int find(int u) {
        return parent[u] == -1 ? u : parent[u] = find(parent[u]);
    }

    bool merge(int u, int v) {
        int ou = u, ov = v;
        u = find(u);
        v = find(v);

        if(u != v) {
            if(height[u] < height[v]) swap(u, v);

            parent[v] = u;
            height[u] = max(height[u], height[v]+1);
            return true;
        }else {
            edge = {ou, ov};
            return false;
        }
    }
};

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<pii>> adjacencies(n+1);
        vector<tiii> edges(m);

        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adjacencies[u].emplace_back(v,w);
            adjacencies[v].emplace_back(u,w);
            edges[i] = {w,u,v};
        }

        sort(edges.begin(), edges.end(), greater<tiii>());

        Dsu dsu(n+1);

        ans = INT_MAX;

        for(auto [w,u,v] : edges) {
            if(!dsu.merge(u,v)) ans = w;
        }

        queue<int> q;
        vector<int> vis(n+1, 0), last(n+1, -1);

        q.push(edge.first);
        q.push(edge.second);
        vis[edge.first] = 1;
        vis[edge.second] = 2;

        pii edge2 = {-1,-1};

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto [adj, w] : adjacencies[node]) {
                if(!vis[adj]) {
                    q.push(adj);
                    vis[adj] = vis[node];
                    last[adj] = node;
                }else if(vis[node] != vis[adj]) {
                    edge2 = {node, adj};
                }
            }
        }

        vector<int> cycle;

        while(edge2.first != -1) {
            cycle.push_back(edge2.first);
            edge2.first = last[edge2.first];
        }

        reverse(cycle.begin(), cycle.end());

        while(edge2.second != -1) {
            cycle.push_back(edge2.second);
            edge2.second = last[edge2.second];
        }

        cout << ans << ' ' << cycle.size() << '\n';

        for(int node : cycle) cout << node << ' ';
        cout << '\n';
    }
}