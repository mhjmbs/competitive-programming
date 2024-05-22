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

int n, m;
vector<vector<int>> adjacencies;
vector<int> vis, inD;



int main() {
    fastio;

    cin >> n >> m;

    adjacencies.resize(n+1);
    vis.resize(n+1, false);
    inD.resize(n+1, 0);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjacencies[v].push_back(u);
        inD[u]++;
    }



    vector<int> ans;
    ans.reserve(n);

    priority_queue<int> prioq;
    for(int i = 1; i <= n; i++) {
        if(inD[i] == 0) prioq.push(i);
    }

    while(!prioq.empty()) {
        int node = prioq.top();
        prioq.pop();

        ans.push_back(node);

        for(int adj : adjacencies[node]) {
            inD[adj]--;
            if(inD[adj] == 0) prioq.push(adj);
        }
    }

    reverse(ans.begin(), ans.end());

    for(int node : ans) cout << node << ' ';
    cout << '\n';
}