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
vector<bool> vis;
vector<int> team;
bool possible = true;

void dfs(int node) {
    vis[node] = true;

    for(int adj : adjacencies[node]) {
        if(!vis[adj]) {
            team[adj] = (team[node] == 1) ? 2 : 1;
            dfs(adj);
        }else {
            if(team[node] == team[adj]) possible = false;
        }
    }
}

int main() {
    fastio;

    cin >> n >> m;

    adjacencies.resize(n+1);
    vis.resize(n+1, false);
    team.resize(n+1);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }

    for(int node = 1; node <= n; node++) {
        if(!vis[node]) {
            team[node] = 1;
            dfs(node);
        }
    }

    if(possible) {
        for(int node = 1; node <= n; node++) {
            cout << team[node] << (node != n ? ' ' : '\n') ;
        }
    }else {
        cout << "IMPOSSIBLE\n";
    }
}