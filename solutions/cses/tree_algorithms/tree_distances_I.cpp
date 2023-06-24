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
using ppi = pair<pii, pii>;
using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

vector<vector<int>> adjacencies;
vector<int> max_dist_to_child, max_dist_parent, max_dist;
vector<ppi> top_2_dist_to_child;

void dfs(int node, int parent) {
    max_dist_to_child[node] = 0;
    top_2_dist_to_child[node] = {{0,-1}, {0,-1}};

    for(int adj : adjacencies[node]) {
        if(adj == parent) continue;

        dfs(adj, node);
        max_dist_to_child[node] = max(max_dist_to_child[node], max_dist_to_child[adj]+1);
    
        pii curr = {max_dist_to_child[adj]+1, adj};

        top_2_dist_to_child[node].first = max(top_2_dist_to_child[node].first, curr);

        if(top_2_dist_to_child[node].first > top_2_dist_to_child[node].second) {
            swap(top_2_dist_to_child[node].first, top_2_dist_to_child[node].second);
        }
    }
}

int main() {
    fastio;

    int n;
    cin >> n;

    adjacencies.resize(n+1);

    for(int i = 0, u, v; i < n-1; i++) {
        cin >> u >> v;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }

    max_dist_to_child.resize(n+1);
    top_2_dist_to_child.resize(n+1);

    dfs(1,0);
    
    max_dist.resize(n+1, 0);
    max_dist_parent.resize(n+1, -1);

    queue<pii> q;
    q.emplace(1, 0);

    while(!q.empty()) {
        auto [node, parent] = q.front();
        q.pop();

        if(node == 1) {
            max_dist[node] = max_dist_to_child[node];
        }else {
            max_dist[node] = max(max_dist_to_child[node], max_dist_parent[node] + 1);
        }

        for(int adj : adjacencies[node]) {
            if(adj == parent) continue;

            q.emplace(adj, node);

            if(adj != top_2_dist_to_child[node].second.second) {
                max_dist_parent[adj] = max(max_dist_parent[node]+1, top_2_dist_to_child[node].second.first);
            }else {
                max_dist_parent[adj] = max(max_dist_parent[node]+1, top_2_dist_to_child[node].first.first);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << max_dist[i] << (i != n ? ' ' : '\n');
    }
}