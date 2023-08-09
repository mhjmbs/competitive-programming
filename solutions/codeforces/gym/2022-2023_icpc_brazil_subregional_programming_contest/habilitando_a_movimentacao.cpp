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

int n, m, curr_time = 0, scc_count = 0;
vector<vector<int>> adjacencies;
vector<int> lowlink, in_time, scc;
stack<int> s;
vector<bool> in_s;

void dfs(int node) {
    lowlink[node] = in_time[node] = ++curr_time;
    s.push(node);
    in_s[node] = true;

    for(int adj : adjacencies[node]) {
        if(in_time[adj] == -1) {
            dfs(adj);
            lowlink[node] = min(lowlink[node], lowlink[adj]);
        }else if(in_s[adj]) {
            lowlink[node] = min(lowlink[node], in_time[adj]);
        }
    }

    if(lowlink[node] == in_time[node]) {
        int curr = -1;
        do {
            curr = s.top();
            s.pop();
            in_s[curr] = false;
            scc[curr] = scc_count;
        }while(curr != node);
        scc_count++;
    }
}

int main() {
    fastio;
    
    cin >> n >> m;

    adjacencies.resize(n+1);
    lowlink.resize(n+1, -1);
    in_time.resize(n+1, -1);
    in_s.resize(n+1, false);
    scc.resize(n+1, -1);

    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adjacencies[u].push_back(v);
    }

    for(int node = 1; node <= n; node++) {
        if(in_time[node] == -1) {
            dfs(node);
        }
    }

    int in = 0, out = 0;
    vector<int> in_degree(scc_count, 0), out_degree(scc_count, 0);

    for(int node = 1; node <= n; node++) {
        for(int adj : adjacencies[node]) {
            if(scc[node] != scc[adj]) {
                in_degree[scc[adj]]++;
                out_degree[scc[node]]++;
            }
        }
    }

    for(int curr_scc = 0; curr_scc < scc_count; curr_scc++) {
        in += in_degree[curr_scc] == 0;
        out += out_degree[curr_scc] == 0;
    }

    if(scc_count == 1) {
        cout << "0\n";
    }else {
        cout << max(in, out) << '\n';
    }
}