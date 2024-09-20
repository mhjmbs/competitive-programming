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
vector<int> permu;
vector<vector<int>> g, h, cost;
ll ans = LONG_LONG_MAX;

void check() {
    vector<vector<int>> new_h(n);

    for(int i = 0; i < n; i++) {
        new_h[permu[i]] = h[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            new_h[permu[i]][permu[j]] = h[i][j];
        }
    }

    ll curr_ans = 0;
    vector<int> inv_permu(n);
    for(int i = 0; i < n; i++) inv_permu[permu[i]] = i;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(g[i][j] != new_h[i][j]) {
                curr_ans += cost[inv_permu[i]][inv_permu[j]];
                new_h[i][j] = new_h[j][i] = !new_h[i][j];
            }
        }
    }

    ans = min(ans, curr_ans);
}

void backtracking(int fixed) {
    if(fixed == n) {
        check();
        return;
    }

    for(int i = fixed; i < n; i++) {
        swap(permu[fixed], permu[i]);

        backtracking(fixed+1);

        swap(permu[fixed], permu[i]);
    }
}

int main() {
    fastio;

    cin >> n;

    g.resize(n, vector<int>(n));
    h.resize(n, vector<int>(n));
    cost.resize(n, vector<int>(n));

    int mg;
    cin >> mg;

    for(int i = 0; i < mg; i++) {
        int u, v;
        cin >> u >> v;
        u--,v--;
        g[u][v] = g[v][u] = 1;
    }

    int mh;
    cin >> mh;

    for(int i = 0; i < mh; i++) {
        int u, v;
        cin >> u >> v;
        u--,v--;
        h[u][v] = h[v][u] = 1;
    }

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            cin >> cost[i][j];
            cost[j][i] = cost[i][j];
        }
    }

    permu.resize(n);
    iota(permu.begin(), permu.end(), 0);

    backtracking(0);

    cout << ans << '\n';
}