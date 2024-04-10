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

int n;
vector<vector<int>> adjacencies;
vector<ll> c, cSum, f;

void dfs(int node, int parent) {
    cSum[node] += c[node];
    for(int adj : adjacencies[node]) {
        if(adj == parent) continue;
        dfs(adj, node);
        cSum[node] += cSum[adj];
    }
}

ll getF(int node, int parent, int dist) {
    ll curr = c[node]*dist;
    for(int adj : adjacencies[node]) {
        if(adj == parent) continue;
        curr += getF(adj, node, dist+1);
    }
    return curr;
}

void reroot(int node, int parent) {
    for(int adj : adjacencies[node]) {
        if(adj == parent) continue;
        f[adj] = f[node] + cSum[node] - 2*cSum[adj];

        cSum[node] -= cSum[adj];
        cSum[adj] += cSum[node];

        reroot(adj, node);

        cSum[adj] -= cSum[node];
        cSum[node] += cSum[adj];
    }
}

int main() {
    fastio;

    cin >> n;

    adjacencies.resize(n+1);
    c.resize(n+1);
    cSum.resize(n+1);
    f.resize(n+1);

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) cin >> c[i];

    dfs(1,0);

    f[1] = getF(1, 0, 0);

    reroot(1, 0);

    cout << *min_element(f.begin()+1, f.end()) << '\n';
}