#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

vector<bool> vis1, vis2;
vector<int> ans;
vector<vector<int>> adjacencies, inv_adjacencies, sccs;
stack<int> s;
 
void dfs1(int node) {
    vis1[node] = true;
    for(int adj : adjacencies[node]) {
        if(!vis1[adj]) dfs1(adj);
    }
    s.push(node);
}
 
void dfs2(int node) {
    vis2[node] = true;
    sccs.back().push_back(node);
    for(int adj : inv_adjacencies[node]) {
        if(!vis2[adj]) dfs2(adj);
    }
}
 
void dfs3(int node) {
    for(int adj : adjacencies[node]) {
        if(ans[adj] == 0 && node != adj) dfs3(adj);
    }
    ans[node] = ans[adjacencies[node][0]]+1;
}
 
int main() {
    fastio;
 
    int n;
    cin >> n;
 
    adjacencies.resize(n+1);
    inv_adjacencies.resize(n+1);
    vis1.resize(n+1, false);
    vis2.resize(n+1, false);
 
    ans.resize(n+1, 0);
 
    for(int u = 1, v; u <= n; u++) {
        cin >> v;
        adjacencies[u].push_back(v);
        inv_adjacencies[v].push_back(u);
    }
 
    for(int i = 1; i <= n; i++) {
        if(!vis1[i]) dfs1(i);
    }
 
    while(!s.empty()) {
        int node = s.top();
        s.pop();
        if(!vis2[node]) {
            sccs.push_back({});
            dfs2(node);
            if(sccs.back().size() > 1) {
                for(int x : sccs.back()) ans[x] = sccs.back().size();
            }
        }
    }
 
    for(int i = 1; i <= n; i++) {
        if(ans[i] == 0) {
            dfs3(i);
        }
    }
 
    for(int i = 1; i <= n; i++) {
        cout << ans[i];
        if(i != n) cout << ' ';
        else cout << '\n';
    }
}