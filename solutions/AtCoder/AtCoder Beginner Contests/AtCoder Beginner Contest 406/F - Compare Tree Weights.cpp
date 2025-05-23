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

struct FenwickTree {
    int n;
    vector<ll> bit;

    FenwickTree(const vector<int>& v) : n(v.size()), bit(n+1) {
        for(int i = 1; i <= n; i++) {
            bit[i] += v[i-1];
            if(i+(i&-i) <= n) bit[i+(i&-i)] += bit[i];
        }
    }

    void sum(int i, ll x) {
        i++;
        while(i <= n) {
            bit[i] += x;
            i += i&-i;
        }
    }

    ll query(int l, int r) {
        l++,r++;
        return query(r) - query(l-1);
    }

    ll query(int i) {
        ll ans = 0;
        while(i > 0) {
            ans += bit[i];
            i -= i&-i;
        }
        return ans;
    }
};

vector<vector<int>> g;
vector<pii> e;
vector<int> sz, tin;

int dfs(int u, int p) {
    static int t = 0;
    tin[u] = t++; 
    sz[u] = 1;

    for(int v : g[u]) {
        if(v == p) continue;
        sz[u] += dfs(v, u);
    }
    return sz[u];
}

int main() {
    fastio;

    int n;
    cin >> n;

    g.resize(n+1);
    sz.resize(n+1);
    tin.resize(n+1);
    e.resize(n);

    for(int m = 0; m < n-1; m++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        e[m+1] = {u,v};
    }

    dfs(1, -1);

    FenwickTree bit(vector<int>(n, 1));

    int q;
    cin >> q;

    while(q--) {
        int qi;
        cin >> qi;

        if(qi == 1) {
            int x, w;
            cin >> x >> w;
            bit.sum(tin[x], w);
        }else {
            int y;
            cin >> y;
            auto [u,v] = e[y];
            if(tin[v] < tin[u]) swap(u,v);
            cout << abs( bit.query(0, n-1) - 2*bit.query(tin[v], tin[v]+sz[v]-1) ) << '\n';
        }
    }
}