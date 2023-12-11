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



int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    vector<int> players(n);

    vector<vector<int>> adjacencies(1 << k);

    for(int i = 0; i < n; i++)
    {
        bitset<20> curr;
        cin >> curr;
        players[i] = curr.to_ulong();
    }

    for(int mask = 0; mask < (1 << k); mask++)
    {
        for(int i = 0; i < k; i++)
        {
            adjacencies[mask].push_back(mask^(1 << i));
        }
    }

    queue<pii> q;
    vector<bool> vis(1 << k, false);
    for(int player : players)
    {
        q.emplace(player, 0);
        vis[player] = true;
    }

    int ans = -1;
    int maxDist = -1;

    while(!q.empty())
    {
        auto [node, dist] = q.front();
        q.pop();
        if(dist > maxDist)
        {
            maxDist = dist;
            ans = node;
        }

        for(int adj : adjacencies[node])
        {
            if(vis[adj])
            {
                continue;
            }

            q.emplace(adj, dist+1);
            vis[adj] = true;
        }
    }

    for(int i = k-1; i >= 0; i--)
    {
        cout << (ans & (1 << i) ? 1 : 0);
    }
    cout << '\n';
}