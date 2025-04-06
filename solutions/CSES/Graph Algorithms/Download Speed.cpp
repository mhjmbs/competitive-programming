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



int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> network(n+1);
    vector<vector<ll>> capacity(n+1, vector<ll>(n+1, 0));

    for(int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        if(capacity[u][v] == 0 && capacity[v][u] == 0) {
            network[u].push_back(v);
            network[v].push_back(u);
        }

        capacity[u][v] += c;
    }

    ll ans = 0;

    while(true) {
        queue<pll> q;
        vector<int> last(n+1, 0);

        ll flow = 0;
        q.emplace(1,1e18);
        last[1] = -1;

        while(!q.empty()) {
            auto [u,f] = q.front();
            q.pop();

            if(u == n) flow = f;

            for(int v : network[u]) {
                if(!last[v] && capacity[u][v] > 0) {
                    last[v] = u;
                    q.emplace(v, min(f,capacity[u][v]));
                }
            }
        }

        if(flow == 0) break;
        ans += flow;

        int u = n;

        while(last[u] != -1) {
            int v = last[u];
            capacity[v][u] -= flow;
            capacity[u][v] += flow;
            u = v;
        }
    }

    cout << ans << '\n';
}