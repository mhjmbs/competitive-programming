#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

void dfs(int node, set<int> &flowerbed, vector<bool> &vis, vector<vector<int>> &adjacencies) {
    vis[node] = true;

    for(int adj : adjacencies[node]) {
        if(flowerbed.count(adj) == 1 && !vis[adj]) {
            dfs(adj, flowerbed, vis, adjacencies);
        }
    }
}

void dfs2(int node, int start, int parent, set<int> &flowerbed, vector<bool> &vis, vector<vector<int>> &adjacencies, bool &poss, int &comp_size) {
    vis[node] = true;
    comp_size++;

    for(int adj : adjacencies[node]) {
        if(!vis[adj]) {
            dfs2(adj, start, node, flowerbed, vis, adjacencies, poss, comp_size);
        }else if(node != start && adj != parent && adj != start) {
            poss = false;
        }
    }
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adjacencies(n+1);
        for(int i = 0, u, v; i < m; i++) {
            cin >> u >> v;
            adjacencies[u].push_back(v);
            adjacencies[v].push_back(u);
        }

        int l = 0, r = 1000, k = -1;
        while(l <= r) {
            int m = (l+r)/2;

            if(m*m < n) {
                l = m+1;
            }else if(m*m > n) {
                r = m-1;
            }else {
                k = m;
                break;
            }
        }

        if(k == -1) {
            cout << "NO\n";
            continue;
        }

        int adj4 = 0, adj2 = 0;
        set<int> flowerbed;

        for(int i = 1; i <= n; i++) {
            if(adjacencies[i].size() == 4) {
                adj4++;
                flowerbed.insert(i);
            }
            if(adjacencies[i].size() == 2) adj2++;
        }

        if(adj4 + adj2 != n || adj4 != k) {
            cout << "NO\n";
            continue;
        }

        vector<bool> vis(n+1, false);

        dfs(*flowerbed.begin(), flowerbed, vis, adjacencies);

        bool poss = true;
        for(int node : flowerbed) if(!vis[node]) poss = false;
        if(!poss) {
            cout << "NO\n";
            continue;
        }

        for(int node : flowerbed) {
            int comp_size = 0;
            dfs2(node, node, -1, flowerbed, vis, adjacencies, poss, comp_size);
            if(comp_size != k) poss = false;
        }

        if(poss) cout << "YES\n";
        else cout << "NO\n";
    }
}