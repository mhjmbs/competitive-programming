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

int n, m;
vector<vector<int>> g(20, vector<int>(20));
ll ans;

const ll md = 998244353;

ll bin_exp(ll a, ll b) {
    a %= md;
    ll ans = 1;
    while(b > 0) {
        if(b&1) ans = ans*a % md;
        a = a*a % md;
        b >>= 1;
    }
    return ans;
}

ll inv(int n) {
    return bin_exp(n, md-2);
}

ll bfs(int root) {
    vector<vector<ll>> cnt(n, vector<ll>(1<<n));
    queue<pii> q;
    ll curr = 0;

    q.emplace(root, 1<<root);
    cnt[root][1<<root] = 1;

    while(!q.empty()) {
        auto [u,mask] = q.front();
        q.pop();

        for(int v = 0; v < n; v++) {
            if(v == root) curr = (curr + cnt[u][mask]*g[u][v]) % md;
            if(g[u][v] == 0 || mask & (1<<v)) continue;
            if(cnt[v][mask|(1<<v)] == 0) q.emplace(v,mask|(1<<v));
            cnt[v][mask|(1<<v)] = (cnt[v][mask|(1<<v)] + g[u][v]*cnt[u][mask]) % md;
        }
    }

    return curr;
}

int main() {
    fastio;

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--,v--;
        g[u][v]++;
        g[v][u]++;
    }

    for(int u = 0; u < n; u++) {
        ll curr = bfs(u);

        for(int v = 0; v < n; v++) {
            curr = ((curr - g[u][v]*g[u][v]) % md + md) % md;
            curr = (curr + g[u][v]*(g[u][v]-1)) % md;
            g[u][v] = g[v][u] = 0;
        }

        ans = (ans + curr*inv(2)) % md;
    }

    cout << ans << '\n';
}