#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

vector<vector<int>> adjacencies, inv_adjacencies;
vector<bool> vis1, vis2, vis3;
stack<int> s;
stack<int> cycle;

vector<set<int>> scc;

void dfs1(int node) {
    vis1[node] = true;
    for(int adj : adjacencies[node]) {
        if(!vis1[adj]) dfs1(adj);
    }
    s.push(node);
}

void dfs2(int node) {
    vis2[node] = true;
    scc.back().insert(node);
    for(int adj : inv_adjacencies[node]) {
        if(!vis2[adj]) dfs2(adj);
    }
}

void dfs3(int node) {
    vis3[node] = true;
    cycle.push(node);
    for(int adj : adjacencies[node]) {
        if(!vis3[adj]) {
            if(scc.back().count(adj) == 1) dfs3(adj);
        }else {
            vector<int> ans;
            ans.push_back(adj);
            while(cycle.top() != adj) {
                ans.push_back(cycle.top());
                cycle.pop();
            }
            ans.push_back(adj);
            reverse(ans.begin(), ans.end());

            cout << ans.size() << '\n';
            for(int i = 0; i < ans.size(); i++) {
                cout << ans[i];
                if(i != ans.size()-1) cout << ' ';
                else cout << '\n';
            }
            exit(0);
        }
    }
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    adjacencies.resize(n+1); 
    inv_adjacencies.resize(n+1);
    vis1.resize(n+1, false);
    vis2.resize(n+1, false);
    vis3.resize(n+1, false);

    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adjacencies[u].push_back(v);
        inv_adjacencies[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        if(!vis1[i]) dfs1(i);
    }

    bool poss = false;

    while(!s.empty()) {
        int node = s.top();
        s.pop();
        if(!vis2[node]) {
            scc.push_back(set<int>());
            dfs2(node);
        }
        if(scc.back().size() > 1) {
            poss = true;
            break;
        }
    }

    if(poss) {
        dfs3(*(scc.back().begin()));
    }else {
        cout << "IMPOSSIBLE\n";
    }
}