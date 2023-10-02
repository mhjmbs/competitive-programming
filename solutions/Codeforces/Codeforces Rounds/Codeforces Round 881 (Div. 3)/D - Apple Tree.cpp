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

vector<vector<int>> adjacencies;
vector<int> leaf_count;

int dfs(int node, int parent) {
    bool is_leaf = (adjacencies[node].size() == 1) && (node != 1);

    for(int adj : adjacencies[node]) {
        if(adj != parent) {
            leaf_count[node] += dfs(adj, node);
        }
    }

    if(is_leaf) leaf_count[node] = 1;

    return leaf_count[node];
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        adjacencies.resize(n+1);
        fill(adjacencies.begin(), adjacencies.end(), vector<int>());

        leaf_count.resize(n+1);
        fill(leaf_count.begin(), leaf_count.end(), 0);

        for(int i = 0, u, v; i < n-1; i++) {
            cin >> u >> v;
            adjacencies[u].push_back(v);
            adjacencies[v].push_back(u);
        }

        dfs(1, 0);

        int q;
        cin >> q;

        for(int i = 0, x, y; i < q; i++) {
            cin >> x >> y;
            cout << ll(leaf_count[x]) * leaf_count[y] << '\n';
        }
    }
}