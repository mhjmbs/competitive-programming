#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

struct Sensor {
    int i;
    int j;
    int r;
};

struct Reach {
    int up;
    int down;
    int left;
    int right;
};

int m, n, k;
vector<bool> vis;
vector<Sensor> sensors;

bool is_adjacent(int u, int v) {
    auto [ui,uj,ur] = sensors[u];
    auto [vi,vj,vr] = sensors[v];

    return (vr+ur) * (vr+ur) >= abs(ui-vi)*abs(ui-vi) + abs(uj-vj)*abs(uj-vj);
}

Reach dfs(int node) {
    vis[node] = true;
    auto [i,j,r] = sensors[node];

    Reach reach = {i-r, i+r, j-r, j+r};

    for(int adj = 0; adj < k; adj++) {
        if(is_adjacent(node, adj) && !vis[adj]) {
            Reach new_reach = dfs(adj);
            reach.up = min(reach.up, new_reach.up);
            reach.down = max(reach.down, new_reach.down);
            reach.left = min(reach.left, new_reach.left);
            reach.right = max(reach.right, new_reach.right);
        }
    }

    return reach;
}

int main() {
    fastio;

    cin >> m >> n >> k;

    sensors.resize(k); 

    for(int i = 0, x, y, r; i < k; i++) {
        cin >> x >> y >> r;
        sensors[i] = {y,x,r};
    }

    vis.resize(k, false);

    vector<Reach> components;

    for(int i = 0; i < k; i++) {
        if(!vis[i]) {
            components.push_back(dfs(i));
        }
    }

    bool yes = true;

    for(Reach r : components) {
        yes = yes &&
        !(r.up <= 0 && (r.left <= 0 || r.down >= n)) &&
        !(r.left <= 0 && r.right >= m) &&
        !(r.right >= m && r.down >= n);
    }

    if(yes) {
        cout << "S\n";
    }else {
        cout << "N\n";
    }
}