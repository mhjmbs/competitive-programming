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

int scc_count = 0;
set<pii> ans;

void dfs(int node, int parent, int &curr_time, vector<int> &lowlink, vector<int> &time, stack<int> &s, vector<bool> &in_s, vector<vector<int>> &adjacencies) {
    lowlink[node] = time[node] = curr_time;
    s.push(node);
    in_s[node] = true;

    for(int adj : adjacencies[node]) {
        if(time[adj] == -1) {
            dfs(adj, node, ++curr_time, lowlink, time, s, in_s, adjacencies);
        }

        if(adj != parent && ans.count(make_pair(adj, node)) == 0) {
            ans.emplace(node, adj);
        }

        if(adj != parent && in_s[adj]) {
            lowlink[node] = min(lowlink[node], lowlink[adj]);
        }
    }

    if(lowlink[node] == time[node]) {
        scc_count++;
        int curr = -1;

        while(curr != node) {
            curr = s.top();
            s.pop();
            in_s[curr] = false;
        }
    }
}

void tarjan(vector<vector<int>> &adjacencies) {
    vector<int> lowlink(adjacencies.size(), -1), time(adjacencies.size(), -1);
    vector<bool> in_s(adjacencies.size(), false);
    stack<int> s;
    int curr_time = 0;

    dfs(1, 0, curr_time, lowlink, time, s, in_s, adjacencies);
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacencies(n+1);
    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }

    tarjan(adjacencies);

    if(scc_count == 1) {
        for(pii curr : ans) {
            cout << curr.first << ' ' << curr.second << '\n';
        }
    }else {
        cout << 0 << '\n';
    }
}