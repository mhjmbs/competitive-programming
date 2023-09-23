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

vector<vector<int>> adjacencies;
vector<int> v, dp, ans;

void dfs(int node, int parent) {
    pii before;

    if(node == 0 || dp.back() < v[node]) {
        dp.push_back(v[node]);
        before = {-1, dp.size()-1};
    }else {
        int pos = upper_bound(dp.begin(), dp.end(), v[node]) - dp.begin();
        before = {dp[pos], pos};
        dp[pos] = v[node];
    }

    ans[node] = dp.size();

    for(int adj : adjacencies[node]) {
        if(adj == parent) continue;
        dfs(adj, node);
    }

    if(before.first == -1) {
        dp.pop_back();
    }else {
        dp[before.second] = before.first; 
    }
}

int main() {
    fastio;

    int n;
    cin >> n;

    adjacencies.resize(n);
    v.resize(n);
    ans.resize(n);
    dp.reserve(n);

    for(int u = 1, v; u < n; u++) {
        cin >> v;
        v--;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }

    for(int &vi : v) cin >> vi;

    dfs(0, -1);

    for(int u = 1; u < n; u++) {
        cout << ans[u] << (u != n-1 ? ' ' : '\n');
    }
}