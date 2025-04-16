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
vector<int> c;

void dfs(int u, int p) {
    c[u] = 1;
    for(int v : g[u]) {
        if(v == p) continue;
        dfs(v, u);
        c[u] += c[v];
    }
}

int dfs2(int u, int p) {
    for(int v : g[u]) {
        if(v == p) continue;
        if(c[v] > n/2) return dfs2(v, u);
    }
    return u;
}

int main() {
    fastio;

    cin >> n;

    g.resize(n+1);
    for(int m = 0; m < n-1; m++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    c.resize(n+1);
    dfs(1, -1);

    cout << dfs2(1, -1) << '\n';
}