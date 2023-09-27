#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using tiii = tuple<int,int,int>;

int n, m;
vector<bool> is_positive_cycle;

vector<set<int>> adjacencies_scc;
vector<ll> dist_scc;
vector<bool> reaches_n, vis;

vector<vector<pii>> adjacencies;
vector<int> d_time, lowlink, scc;
vector<bool> in_s;
stack<int> s;
int curr_time = 0, curr_scc = 0;

ll bellman_ford() {
    vector<ll> dist(n+1, ll(-1e17));
    dist[1] = 0;

    for(int i = 0; i < n-1; i++) {
        for(int node = 1; node <= n; node++) {
            for(pii adj : adjacencies[node]) {
                if(dist[node] + adj.second > dist[adj.first]) {
                    dist[adj.first] = dist[node] + adj.second;
                }
            }
        }
    }

    return dist[n];
}

void dfs(int node) {
    vis[node] = true;

    for(int adj : adjacencies_scc[node]) {
        if(!vis[adj]) dfs(adj);
        reaches_n[node] = reaches_n[node] || reaches_n[adj];
    }
}

bool has_positive_cycle(vector<tiii> &edges, set<int> &set_scc) {
    dist_scc[*(set_scc.begin())] = 0;

    for(int i = 0; i <= set_scc.size(); i++) {
        for(tiii edge : edges) {
            int u, v, c;
            tie(u, v, c) = edge;
            if(dist_scc[u] + c > dist_scc[v]) {
                dist_scc[v] = dist_scc[u] + c;
                if(i == set_scc.size()) return true;
            }
        }
    }

    return false;
}

void tarjan(int node) {
    d_time[node] = lowlink[node] = ++curr_time;
    
    s.push(node);
    in_s[node] = true;

    for(pii adj : adjacencies[node]) {
        if(d_time[adj.first] == -1) {
            tarjan(adj.first);
        }

        if(in_s[adj.first]) lowlink[node] = min(lowlink[node], lowlink[adj.first]);
    }

    if(lowlink[node] == d_time[node]) {
        int last_top = -1;
        set<int> set_scc;
        while(last_top != node) {
            last_top = s.top();
            s.pop();
            in_s[last_top] = false;
            scc[last_top] = curr_scc;
            set_scc.insert(last_top);
        }

        vector<tiii> edges_curr_scc;
        for(int x : set_scc) {
            for(pii adj : adjacencies[x]) {
                if(set_scc.count(adj.first) == 1) {
                    edges_curr_scc.emplace_back(x, adj.first, adj.second);
                }
            }
        }

        is_positive_cycle.push_back(has_positive_cycle(edges_curr_scc, set_scc));
        curr_scc++;
    }
}

int main() {
    fastio;

    cin >> n >> m;

    adjacencies.resize(n+1);
    d_time.resize(n+1, -1);
    lowlink.resize(n+1);
    in_s.resize(n+1, false);
    scc.resize(n+1);
    dist_scc.resize(n+1, ll(-1e17));

    for(int i = 0, u, v, c; i < m; i++) {
        cin >> u >> v >> c;
        adjacencies[u].emplace_back(v,c);
    }

    for(int i = 1; i <= n; i++) if(d_time[i] == -1) tarjan(i);

    adjacencies_scc.resize(curr_scc);

    for(int i = 1; i <= n; i++) {
        for(pii adj : adjacencies[i]) adjacencies_scc[scc[i]].insert(scc[adj.first]);
    }

    reaches_n.resize(curr_scc, false);
    reaches_n[scc[n]] = true;

    vis.resize(curr_scc);

    dfs(scc[1]);

    for(int i = 0; i < curr_scc; i++) {
        if(reaches_n[i] && is_positive_cycle[i]) {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << bellman_ford() << '\n';
}