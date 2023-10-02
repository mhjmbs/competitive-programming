#include "bits/stdc++.h"
 
#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)
 
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

int dfs(int node, int curr_dist, vector<vector<int>> &adjacencies, vector<int> &md_child, vector<int> &d_root, vector<bool> &vis, vector<int> &p) {
    vis[node] = true;
    d_root[node] = curr_dist;

    for(int adj : adjacencies[node]) {
        if(!vis[adj]) {
            int curr_md_child = dfs(adj, curr_dist+1, adjacencies, md_child, d_root, vis, p);
            md_child[node] = max(md_child[node], curr_md_child+1);
            p[adj] = node;
        }
    }

    return md_child[node];
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        ll n, k, c;
        cin >> n >> k >> c;

        vector<vector<int>> adjacencies(n+1);
        for(int i = 0, u, v; i < n-1; i++) {
            cin >> u >> v;
            adjacencies[u].push_back(v);
            adjacencies[v].push_back(u);
        }

        vector<int> md_child(n+1, 0), d_root(n+1), md_p_not_me(n+1, 0), md(n+1, 0), p(n+1, 0);
        vector<bool> vis(n+1, false);

        dfs(1, 0, adjacencies, md_child, d_root, vis, p);
        
        fill(vis.begin(), vis.end(), false);

        queue<int> q;
        q.push(1);
        vis[1] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int adj : adjacencies[node]) {
                if(!vis[adj]) {
                    q.push(adj);
                    vis[adj] = true;
                }
            }

            md[node] = max(md_child[node], md_p_not_me[node]+1);

            multiset<int> md_adj_child_set;
            vector<int> md_adj_child_v, children;

            for(int adj : adjacencies[node]) {
                if(adj == p[node]) continue;
                children.push_back(adj);
                md_adj_child_v.push_back(md_child[adj]);
                md_adj_child_set.insert(md_child[adj]);
            }

            for(int i = 0; i < children.size(); i++) {
                md_adj_child_set.erase(md_adj_child_set.lower_bound(md_adj_child_v[i]));
                
                if(node != 1) md_p_not_me[children[i]] = md_p_not_me[node]+1;
                if(!md_adj_child_set.empty()) md_p_not_me[children[i]] = max(md_p_not_me[children[i]], *md_adj_child_set.rbegin()+1);

                md_adj_child_set.insert(md_adj_child_v[i]);
            }
        }

        ll ans = 0;

        for(int i = 1; i <= n; i++) {
            ans = max(ans, (md[i])*k - d_root[i]*c);
        }

        cout << ans << '\n';
    }
}