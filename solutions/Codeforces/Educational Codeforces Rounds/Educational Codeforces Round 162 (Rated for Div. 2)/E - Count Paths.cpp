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

vector<vector<int>> adjacencies;
vector<int> c;
vector<map<int,ll>> poss;
ll ans;

void dfs(int node, int parent) {
    for(int adj : adjacencies[node]) {
        if(adj == parent) continue;
        dfs(adj, node);
    }

    for(int adj : adjacencies[node]) {
        if(poss[adj].count(c[node]) > 0) ans += poss[adj][c[node]];
        if(poss[adj].size() > poss[node].size()) swap(poss[node], poss[adj]);
        for(auto [color, freq] : poss[adj]) {
            if(color == c[node]) continue;
            else {
                if(poss[node].count(color) > 0) ans += poss[node][color]*freq;
                poss[node][color] += freq;
            }
        }
    }

    poss[node][c[node]] = 1;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        c.resize(n+1);
        for(int i = 1; i <= n; i++) cin >> c[i];

        adjacencies.assign(n+1, vector<int>());
        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            adjacencies[u].push_back(v);
            adjacencies[v].push_back(u);
        }

        ans = 0;
        poss.assign(n+1, map<int,ll>());

        dfs(1,-1);

        cout << ans << '\n';
    }
}