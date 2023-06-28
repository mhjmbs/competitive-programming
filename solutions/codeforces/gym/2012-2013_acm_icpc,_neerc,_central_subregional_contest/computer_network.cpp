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

int n, m, curr_time = 0, best = 0;
vector<vector<int>> adjacencies;
vector<vector<bool>> is_tree_edge, vis_edges;
vector<int> lowlink, tin, bridge_count, leaf_of;
pii ans = {1,2};

void find_info(int node, int parent) {
    lowlink[node] = tin[node] = ++curr_time;
    bool saw_parent = false;

    for(int adj : adjacencies[node]) {
        if(adj == parent && !saw_parent) {
            saw_parent = true;
            continue;
        }

        if(tin[adj] == -1) {
            is_tree_edge[node][adj] = is_tree_edge[adj][node] = true;
            find_info(adj, node);
        }

        lowlink[node] = min(lowlink[node], lowlink[adj]);
    }
}

void dp(int node, int parent) {
    ppi top_2 = {{0,node},{0,node}};
    leaf_of[node] = node;

    for(int adj : adjacencies[node]) {
        if(!is_tree_edge[node][adj] || vis_edges[node][adj]) continue;
        vis_edges[node][adj] = vis_edges[adj][node] = true;

        dp(adj, node);

        int bridge_path = bridge_count[adj] + (tin[node] < lowlink[adj] ? 1 : 0);

        if(top_2.first.first <= bridge_path) {
            top_2.first = {bridge_path, leaf_of[adj]};
            if(top_2.first.first > top_2.second.first) {
                swap(top_2.first, top_2.second);
                bridge_count[node] = bridge_path;
                leaf_of[node] = leaf_of[adj]; 
            }
        }
    }

    if(top_2.first.first + top_2.second.first > best) {
        best = top_2.first.first + top_2.second.first;
        ans = {top_2.first.second, top_2.second.second};
    }
}

int main() {
    fastio;

    freopen("input.txt", "r", stdin);
    cin >> n >> m;

    vis_edges.resize(n+1, vector<bool>(n+1, false));
    is_tree_edge.resize(n+1, vector<bool>(n+1, false));
    adjacencies.resize(n+1);
    leaf_of.resize(n+1);
    lowlink.resize(n+1, -1);
    tin.resize(n+1, -1);
    bridge_count.resize(n+1, 0);

    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }

    find_info(1, 0);
    dp(1, 0);

    freopen("output.txt", "w", stdout);
    cout << ans.first << ' ' << ans.second << '\n';
}