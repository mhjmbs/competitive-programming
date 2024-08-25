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

int n, k;
vector<vector<int>> adjacencies;
vector<int> inV;

int dfs(int node, int last) {
    int curr = 0;

    for(int adj : adjacencies[node]) {
        if(adj == last) continue;
        curr += dfs(adj, node);
    }

    if(curr > 0) curr++;
    else curr = inV[node];

    return curr;
}

int main() {
    fastio;

    cin >> n >> k;
    adjacencies.resize(n+1);

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }

    inV.resize(n+1);
    int root = -1;
    for(int i = 0; i < k; i++) {
        int vi;
        cin >> vi;
        inV[vi] = true;
        root = vi;
    }

    cout << dfs(root, -1) << '\n';
}