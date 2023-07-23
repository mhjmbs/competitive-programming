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

int n, k;
vector<vector<int>> adjacencies;
vector<bool> vis;
priority_queue<int> chains;

int dfs(int node) {
    vis[node] = true;
    int best_path = 0;

    priority_queue<int, vector<int>, greater<int>> depths;

    for(int adj : adjacencies[node]) {
        if(!vis[adj]) {
            depths.push(dfs(adj));
        }
    }

    while(depths.size() > 1) {
        chains.push(depths.top());
        depths.pop();
    }

    if(!depths.empty()) best_path = depths.top();

    return best_path + 1;
}

int main(){
    fastio;
    
    cin >> n >> k;

    adjacencies.resize(n+1);
    vis.resize(n+1, false);

    for(int i = 2, p; i <= n; i++) {
        cin >> p;
        adjacencies[i].push_back(p);
        adjacencies[p].push_back(i);
    }

    chains.push(dfs(1));

    int ans = 0;

    while(k-- && !chains.empty()) {
        ans += chains.top();
        chains.pop();
    }

    cout << ans << '\n';

    return 0;
}