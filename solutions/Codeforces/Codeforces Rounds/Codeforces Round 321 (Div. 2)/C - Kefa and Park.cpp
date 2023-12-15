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

int n, m;
vector<vector<int>> adjacencies;
vector<bool> vis, hasCat;
int ans = 0;

bool isLeaf(int node) {
    return adjacencies[node].size() == 1 && node != 0;
}

void dfs(int node, int catCount) {
    vis[node] = true;

    if(catCount > m) return;

    if(isLeaf(node)) ans++;

    for(int adj : adjacencies[node]) {
        if(!vis[adj]) {
            if(hasCat[adj]) {
                dfs(adj, catCount+1);
            }else {
                dfs(adj, 0);
            }
        }
    }
}

int main() {
    fastio;

    cin >> n >> m;

    adjacencies.resize(n);
    vis.resize(n, false);
    hasCat.resize(n, false);

    for(int i = 0, ai; i < n; i++) {
        cin >> ai;
        hasCat[i] = ai;
    }

    for(int i = 0, u, v; i < n-1; i++) {
        cin >> u >> v;
        u--; v--;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }

    dfs(0, hasCat[0]);

    cout << ans << '\n';
}