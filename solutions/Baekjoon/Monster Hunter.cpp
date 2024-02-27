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
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

void dfs(int node, int parent, vector<vector<int>>& adjacencies, vector<int>& p) {
    p[node] = parent;
    for(int adj : adjacencies[node]) {
        if(adj == parent) continue;
        dfs(adj, node, adjacencies, p);
    }
}

class comp {
    public:
    bool operator()(tlll a, tlll b) {
        auto [d1, v1, u] = a;
        auto [d2, v2, v] = b;

        if(d1 <= v1 && d2 <= v2) return d1 > d2;
        if(d1 <= v1) return false;
        if(d2 <= v2) return true;
        return v1 < v2;
    }
};

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

    void merge(int u, int v) {
        u = find(u);
        v = find(v);

        if(u != v) {
            if(height[u] < height[v]) swap(u, v);

            parent[v] = u;
            height[u] = max(height[u], height[v]+1);
        }
    }
};

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<pll> monsters(n+1);
        monsters[1] = {0,0};
        for(int i = 2; i <= n; i++) cin >> monsters[i].first >> monsters[i].second;

        vector<vector<int>> adjacencies(n+1);
    
        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            adjacencies[u].push_back(v);
            adjacencies[v].push_back(u);
        }

        vector<int> p(n+1);

        dfs(1, -1, adjacencies, p);

        priority_queue<tlll, vector<tlll>, comp> prioq;

        for(int i = 2; i <= n; i++) prioq.emplace(monsters[i].first, monsters[i].second, i);

        Dsu dsu(n+1);

        while(!prioq.empty()) {
            auto[d1, r1, u] = prioq.top();
            prioq.pop();
            
            if(u != dsu.find(u) || monsters[u] != make_pair(d1,r1)) continue;

            int v = dsu.find(p[u]);
            auto[d2, r2] = monsters[v];

            dsu.merge(u,v);
            int w = dsu.find(u);
            monsters[w] = {max(d2, d2-r2+d1), -d2+r2-d1+r1 + max(d2, d2-r2+d1)};
            p[w] = p[v];
            if(p[w] != -1) prioq.emplace(monsters[w].first, monsters[w].second, w);
        }

        cout << monsters[dsu.find(1)].first << '\n';
    }
}