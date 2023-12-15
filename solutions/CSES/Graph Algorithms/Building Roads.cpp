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
vector<bool> vis;

void dfs(int node) {
    vis[node] = true;

    for(int adj : adjacencies[node]) {
        if(!vis[adj]) {
            dfs(adj);
        }
    }
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    adjacencies.resize(n);
    vis.resize(n, false);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }

    int cc = 0;
    vector<int> ans;

    for(int node = 0; node < n; node++) {
        if(!vis[node]) {
            ans.push_back(node);
            cc++;
            dfs(node);
        }
    }

    cout << cc-1 << '\n';
    for(int i = 1; i < ans.size(); i++) {
        cout << ans[i-1]+1 << ' ' << ans[i]+1 << '\n';
    }
}