#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct DSU {
    vector<int> height, rep;

    DSU(int n) : height(n, 0), rep(n) {
        iota(rep.begin(), rep.end(), 0);
    }

    int find(int u) {
        return (rep[u] == u) ? u : rep[u] = find(rep[u]); 
    }

    bool merge(int u, int v) {
        u = find(u);
        v = find(v);

        if(u == v) return false;
    
        if(height[u] < height[v]) swap(u,v);

        rep[v] = u;
        height[u] = max(height[u], height[v]+1);
        return true;
    }
};


int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;

        vector<vector<int>> adjacencies(n);
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--,v--;
            adjacencies[u].push_back(v);
            adjacencies[v].push_back(u);
        }

        queue<int> q;
        vector<int> vis(n), dist(n, 1e9), black(n, -1);
        
        for(int u = 0; u < n; u++) {
            if(s[u] == '1') {
                q.push(u);
                vis[u] = true;
                dist[u] = 0;
                black[u] = u;
            }
        }
        
        DSU dsu(n);
        ll ans = 0;
        vector<tiii> merges;
    
        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int v : adjacencies[u]) {
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                    dist[v] = dist[u]+1;
                    black[v] = black[u];
                }else {
                    merges.emplace_back(dist[u]+dist[v]+1, black[u], black[v]);
                }
            }
        }

        sort(merges.begin(), merges.end());

        for(auto [w, u, v] : merges) {
            if(dsu.merge(u,v)) ans += w;
        }

        cout << ans << '\n';
    }
}