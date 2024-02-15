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

void dfs(int node, vector<set<int>>& adjacencies, vector<int>& vis, int& yes, int tag) {
    vis[node] = tag;

    for(int adj : adjacencies[node]) {
        if(!vis[adj]) dfs(adj, adjacencies, vis, yes, tag);
        else if(vis[adj] == tag) yes = false;
    }
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<set<int>> adjacencies(n+1);
        vector<vector<int>> screenshots(k, vector<int>(n));

        for(int i = 0; i < k; i++) {
            for(int j = 0; j < n; j++) {
                cin >> screenshots[i][j];
            }
        }

        vector<int> inDegree(n+1, 0);

        for(int i = 0; i < k; i++) {
            for(int j = 2; j < n; j++) {
                if(adjacencies[screenshots[i][j-1]].count(screenshots[i][j]) == 0) inDegree[screenshots[i][j]]++;
                adjacencies[screenshots[i][j-1]].insert(screenshots[i][j]);
            }
        }

        queue<int> q;
        vector<int> vis(n+1, false);
        for(int node = 1; node <= n; node++) {
            if(inDegree[node] == 0) {
                q.push(node);
                vis[node] = true;
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int adj : adjacencies[node]) {
                inDegree[adj]--;
                if(inDegree[adj] == 0) {
                    q.push(adj);
                    vis[adj] = true;
                }
            }
        }

        bool yes = all_of(vis.begin()+1, vis.end(), [](int x) {return x;});

        cout << (yes ? "YES\n" : "NO\n");
    }
}