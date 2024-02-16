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

int n, q;
vector<int> e, tin, tout, eulerTour, depth;
vector<vector<int>> adjacencies, up;

struct BIT {
    vector<ull> bit;

    BIT(vector<int>& v) : bit(v.size()+1, 0) {
        for(int i = 1; i < bit.size(); i++) {
            bit[i] ^= v[i-1];
            if(i+(i&-i) < bit.size()) bit[i+(i&-i)] ^= bit[i];
        }
    }

    void upd(int i, ull val) {
        ll diff = val ^ query(i,i);
        i++;
        while(i < bit.size()) {
            bit[i] ^= diff;
            i += i&-i;
        }
    }

    ull query(int l, int r) {
        l++, r++;
        return query(r) ^ query(l-1);
    }

    ull query(int r) {
        ull ans = 0;
        while(r > 0) {
            ans ^= bit[r];
            r -= r&-r;
        }
        return ans;
    }
};

void computeUps() {
    for(int i = 1; i < up.size(); i++) {
        for(int u = 1; u <= n; u++) {
            up[i][u] = up[i-1][up[i-1][u]];
        }
    }
}

void dfs(int u, int p, int currDepth) {
    static int t = 0;
    tin[u] = t++;
    eulerTour[tin[u]] = u;
    depth[u] = currDepth;
    up[0][u] = p;

    for(int adj : adjacencies[u]) {
        if(adj == p) continue;
        dfs(adj, u, currDepth+1);
    }

    tout[u] = t++;
}

int lca(int u, int v) {
    if(depth[u] > depth[v]) swap(u,v);
    int diff = depth[v] - depth[u];
    for(int i = 0; i < up.size(); i++) {
        if(diff&(1<<i)) v = up[i][v];
    }

    if(u == v) return u;

    for(int i = up.size()-1; i >= 0; i--) {
        if(up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    }

    return up[0][u];
}

int main() {
    fastio;

    ifstream cin("cowland.in");
    ofstream cout("cowland.out");

    cin >> n >> q;

    e.resize(n+1);
    for(int i = 1; i <= n; i++) cin >> e[i];

    adjacencies.resize(n+1);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }

    tin.resize(n+1);
    tout.resize(n+1);
    eulerTour.resize(2*n);
    depth.resize(n+1);
    up.resize(ceil(log2(n)), vector<int>(n+1));

    dfs(1, -1, 0);
    computeUps();

    vector<int> newE(2*n);
    for(int u = 1; u <= n; u++) {
        newE[tin[u]] = e[u];
        newE[tout[u]] = e[u];
    }

    BIT bit(newE);

    while(q--) {
        int tq;
        cin >> tq;

        if(tq == 1) {
            int i, v;
            cin >> i >> v;
            bit.upd(tin[i], v);
            bit.upd(tout[i], v);
        }else {
            int i, j;
            cin >> i >> j;
            cout << ( bit.query(tin[lca(i,j)], tin[i]) ^ bit.query(tin[lca(i,j)], tin[j]) ^ bit.query(tin[lca(i,j)], tin[lca(i,j)]) ) << '\n';
        }
    }
}