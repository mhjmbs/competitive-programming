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

struct Dsu {
    vector<int> parent;
    vector<int> height;
    vector<int> size;
    vector<ll> weight;

    Dsu(int n) {
        height.resize(n, 0);
        parent.resize(n, -1);
        size.resize(n, 1);
        weight.resize(n, 0);
    }

    int find(int u) {
        return parent[u] == -1 ? u : parent[u] = find(parent[u]);
    }

    void merge(int u, int v, int c) {
        u = find(u);
        v = find(v);

        if(u != v) {
            if(height[u] < height[v]) swap(u, v);

            parent[v] = u;
            height[u] = max(height[u], height[v]+1);
            size[u] += size[v];
            weight[u] += weight[v] + c; 
        }
    }
};

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    vector< pair<int,vector<int>> > queries(m);

    for(int i = 0; i < m; i++) {
        int k, c;
        cin >> k >> c;

        queries[i] = {c,vector<int>(k)};

        for(int& ai : queries[i].second) cin >> ai;
    }

    sort(queries.begin(), queries.end());
    Dsu dsu(n+1);

    for(auto& [c, nodes] : queries) {
        for(int i = 0; i < nodes.size(); i++) {
            dsu.merge(nodes[0], nodes[i], c);
        }
    }

    if(dsu.size[dsu.find(1)] == n) cout << dsu.weight[dsu.find(1)] << '\n';
    else cout << -1 << '\n';
}