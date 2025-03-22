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

vector<vector<int>> adjacencies;
vector<int> in_d, dp;

int main() {
    fastio;

    int n;
    cin >> n;

    adjacencies.resize(n+1);
    in_d.resize(n+1);
    dp.resize(n+1);

    for(int u = 1; u <= n; u++) {
        int c;
        cin >> c;

        for(int j = 0; j < c; j++) {
            int v;
            cin >> v;
            adjacencies[u].push_back(v);
            in_d[v]++;
        }
    }

    queue<int> q;

    for(int u = 1; u <= n; u++) {
        if(in_d[u] == 0) {
            q.push(u);
            dp[u] = 1;
        }
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v : adjacencies[u]) {
            // cout << v << '\n';
            dp[v] = max(dp[u]+1, dp[v]);
            in_d[v]--;
            if(in_d[v] == 0) q.push(v);
        }
    }

    // for(int u = 1; u <= n; u++) cout << dp[u] << ' ';
    // cout << '\n';

    cout << (count(dp.begin(), dp.end(), n) > 0) << '\n';
}