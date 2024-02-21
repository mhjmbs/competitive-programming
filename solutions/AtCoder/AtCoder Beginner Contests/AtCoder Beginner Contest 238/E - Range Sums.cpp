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



int main() {
    fastio;

    int n, q;
    cin >> n >> q;

    vector<vector<int>> adjacencies(n+1);

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        adjacencies[l-1].push_back(r);
        adjacencies[r].push_back(l-1);
    }

    vector<bool> vis(n+1, false);
    queue<int> queue;
    queue.push(0);
    vis[0] = true;

    while(!queue.empty()) {
        int node = queue.front();
        queue.pop();

        for(int adj : adjacencies[node]) {
            if(!vis[adj]) {
                queue.push(adj);
                vis[adj] = true;
            }
        }
    }

    cout << (vis[n] ? "Yes\n" : "No\n");
}