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
vector<int> last;
 
void printCycle(int cycleEnd, int cycleBegin) {
    vector<int> cycle;

    int node = cycleEnd;
    while(node != cycleBegin) {
        cycle.push_back(node);
        node = last[node];
    }
    cycle.push_back(cycleBegin);
    cycle.push_back(cycleEnd);

    cout << cycle.size() << '\n';
 
    for(int i = 0; i < cycle.size(); i++) {
        cout << cycle[i] << (i != cycle.size()-1 ? ' ' : '\n');
    }
}
 
void dfs(int node, int previous) {
    vis[node] = true;
    last[node] = previous;
 
    for(int adj : adjacencies[node]) {
        if(!vis[adj]) {
            dfs(adj, node);
        }else if(previous != adj) {
            printCycle(node, adj);
            exit(0);
        }
    }
}
 
int main() {
    fastio;
 
    int n, m;
    cin >> n >> m;
 
    adjacencies.resize(n+1);
    vis.resize(n+1, false);
    last.resize(n+1, -1);
 
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }
 
    for(int node = 1; node <= n; node++) {
        if(!vis[node]) {
            dfs(node, -1);
        }
    }
 
    cout << "IMPOSSIBLE\n";
}