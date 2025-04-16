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

int n;
vector<vector<int>> g;
vector<int> d;
ll ans = 0;
ll m = 998244353;

void dfs(int u, int p) {
    for(int v : g[u]) {
        if(v == p) continue;
        dfs(v, u);
        d[u] = max(d[u], d[v]+1);
    }
}

void reroot(int u, int p) {
    int mx1 = -1, mx2 = -1;
    int v1 = -1, v2 = -1;
    for(int v : g[u]) {
        if(d[v]+1 > mx2) mx2 = d[v], v2 = v;
        if(mx1 < mx2) swap(mx1, mx2), swap(v1,v2);
    }

    ans = (ans + mx2+1 + 1) % m;
    
    for(int v : g[u]) {
        if(v == p) continue;
        int ldv = d[v];
        if(v == v1) d[u] = mx2+1;
        ans = (ans + min(d[u],d[v])+1) % m;
        d[v] = max(d[v], d[u]+1);
        reroot(v, u);
        d[v] = ldv;
        d[u] = mx1;
    }
}

int main() {
    fastio;

    int t;
    cin >> t;
    
    while(t--) {
        cin >> n;
        
        g.assign(n+1, {});
        d.assign(n+1, 0);
        
        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        dfs(1, -1);
        ans = 0;
        reroot(1, -1);
        
        cout << ans << '\n';
    }
}