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
 
 
int n, k1, k2;
ll ans = 0;
vector<vector<int>> g;
vector<int> c, del;
 
void dfs(int u, int p) {
    c[u] = 1;
    for(int v : g[u]) {
        if(v == p || del[v]) continue;
        dfs(v, u);
        c[u] += c[v];
    }
}
 
int dfs2(int u, int n) {
    for(int v : g[u]) {
        if(!del[v] && c[v] > n/2) {
            c[u] -= c[v];
            c[v] += c[u];
            return dfs2(v, n);
        }
    }
    return u;
}
 
void dfs3(int u, int p, int d, vector<int>& paths) {
    paths[d]++;
    for(int v : g[u]) {
        if(v == p || del[v]) continue;
        dfs3(v, u, d+1, paths);
    }
}
 
void solve(int u) {
    dfs(u, -1);
    int centroid = dfs2(u, c[u]);
    del[centroid] = true;

    vector<int> p(c[centroid]);
    p[0] = 1;
    
    ll sum0 = 0;
    for(int i = max(0, k1-1); i < min(k2, c[centroid]); i++) {
        sum0 += p[i];
    }

    for(int v : g[centroid]) {
        if(!del[v]) {
            vector<int> vp(c[v]);
            dfs3(v, -1, 0, vp);

            ll sum = sum0;
            int l = k1-1, r = k2-1;

            for(int i = 0; i < c[v]; i++) {
                ans += vp[i]*sum;
                if(0 <= r && r < c[centroid]) sum -= p[r];
                r--;
                l--;
                if(0 <= l && l < c[centroid]) sum += p[l];
            }
            
            for(int i = 0; i < vp.size(); i++) {
                p[i+1] += vp[i];
                if(k1-1 <= i+1 && i+1 <= k2-1) sum0 += vp[i];
            }
        }
    }
    
    for(int v : g[centroid]) {
        if(!del[v]) solve(v);
    }
}
 
int main() {
    fastio;
    
    cin >> n >> k1 >> k2;
 
    g.resize(n+1);
 
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    c.resize(n+1);
    del.resize(n+1);
    solve(1);
 
    cout << ans << '\n';
}