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



int main() {
    fastio;

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> adjacencies(n+1);

    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }

    vector<pii> guards(k+1);

    for(int i = 1, p, h; i <= k; i++) {
        cin >> p >> h;
        guards[i] = {h,p};
    }

    vector<int> max_energy(n+1, -1);
    priority_queue<pii> q;

    for(int i = 1; i <= k; i++) {
        auto [h,p] = guards[i];
        q.emplace(h, p);
        max_energy[p] = max(max_energy[p], h);
    }

    vector<bool> vis(n+1, false);
    int vis_count = 0;

    while(!q.empty()) {
        auto [energy,node] = q.top();
        q.pop();

        if(!vis[node]) {
            vis_count++;
            vis[node] = true;
        }

        for(int adj : adjacencies[node]) {
            if(max_energy[adj] < energy-1) {
                max_energy[adj] = energy-1;
                q.emplace(max_energy[adj], adj);
            }
        }
    }

    cout << vis_count << '\n';

    for(int i = 1; i <= n; i++) {
        if(vis[i]) {
            cout << i << (vis_count != 1 ? ' ' : '\n');
            vis_count--;
        }
    }
}