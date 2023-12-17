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

int n, m;
vector<vector<int>> adjacencies;

queue<pii> q;
vector<bool> enqueued;
vector<int> last;

void printPath() {
    vector<int> path;

    int node = n;
    while(node != 1) {
        path.push_back(node);
        node = last[node];
    }
    path.push_back(1);

    reverse(path.begin(), path.end());

    for(int i = 0; i < path.size(); i++) {
        cout << path[i] << (i != path.size()-1 ? ' ' : '\n');
    }
}

int main() {
    fastio;

    cin >> n >> m;

    adjacencies.resize(n+1);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }

    queue<pii> q;
    enqueued.resize(n+1, false);
    last.resize(n+1, -1);

    q.emplace(1, 0);
    enqueued[1] = true;

    while(!q.empty()) {
        auto [node, dist] = q.front();
        q.pop();

        if(node == n) {
            cout << dist+1 << '\n';
            printPath();
            exit(0);
        }

        for(int adj : adjacencies[node]) {
            if(!enqueued[adj]) {
                last[adj] = node;
                q.emplace(adj, dist+1);
                enqueued[adj] = true;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}