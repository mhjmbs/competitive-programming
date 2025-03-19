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

int n, k;
vector<vector<int>> adjacencies;
bool yes = true;

int dfs(int u, int p) {
    vector<int> c;

    for(int v : adjacencies[u]) {
        if(v == p) continue;
        int path = dfs(v,u);
        if(path != 0) c.push_back(path);
    }

    int up = 1;

    if(c.size() > 2) {
        yes = false;
    }else if(c.size() == 1) {
        up = c[0]+1;
    }else if(c.size() == 2) {
        if(c[0] + c[1] + 1 == k) up = 0;
        else yes = false;
    }

    return (up != k) ? up : 0;
}

int main() {
    fastio;

    cin >> n >> k;

    adjacencies.resize(n*k+1);
    for(int i = 0; i < n*k-1; i++) {
        int u, v;
        cin >> u >> v;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }

    yes = (dfs(1, -1) == 0) && yes;

    cout << (yes ? "Yes\n" : "No\n");
}