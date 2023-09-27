#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

vector<vector<int>> adjacencies;
vector<int> rep, sz;
vector<bool> vis;
vector<ll> cost;
ll ans = 0;
 
int f(int a) {
    if(rep[a] == a) return a;
    return rep[a] = f(rep[a]);
}

void u(int a, int b, int c) {
    a = f(a);
    b = f(b);
    if(a == b) return;
    if(a > b) swap(a,b);
    rep[a] = b;
    sz[b] += sz[a];
    cost[b] += cost[a]+c;
    ans = cost[b];
}

void dfs(int node) {
    vis[node] = true;
    for(int adj : adjacencies[node]) {
        if(!vis[adj]) dfs(adj);
    }
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
 
    rep.resize(n+1);
    sz.resize(n+1, 1);
    cost.resize(n+1, 0);
    adjacencies.resize(n+1);
    vis.resize(n+1, false);
    
    for(int i = 1; i <= n; i++) rep[i] = i, sz[i] = 1;

    priority_queue<tiii, vector<tiii>, greater<tiii>> prioq;
    for(int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        prioq.emplace(c,a,b);
        adjacencies[a].push_back(b);
        adjacencies[b].push_back(a);
    }

    dfs(1);

    if(*min_element(vis.begin()+1, vis.end()) == false) {
        cout << "IMPOSSIBLE\n";
    }else {
        while(!prioq.empty()) {
            int a, b, c;
            tie(c,a,b) = prioq.top();
            prioq.pop();
            u(a,b,c);
        }
        cout << ans << '\n';
    }
}