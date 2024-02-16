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

int n;
vector<int> c, ans;
vector<vector<int>> adjacencies;

set<int> dfs(int node, int parent) {
    set<int> s = {c[node]};
    for(int adj : adjacencies[node]) {
        if(parent == adj) continue;
        set<int> s2 = dfs(adj, node);
        if(s.size() < s2.size()) s.swap(s2);
        s.merge(s2);
    }
    ans[node] = s.size();
    return s;
}

int main() {
    fastio;

    cin >> n;

    c.resize(n+1);
    for(int i = 1; i <= n; i++) cin >> c[i];

    adjacencies.resize(n+1);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }

    ans.resize(n+1);

    dfs(1, -1);

    for(int node = 1; node <= n; node++) {
        cout << ans[node] << (node != n ? ' ' : '\n');
    }
}