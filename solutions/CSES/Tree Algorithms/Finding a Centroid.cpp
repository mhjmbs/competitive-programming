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

int n;
vector<vector<int>> adjacencies;
vector<int> subtreeSize;
vector<bool> vis;

int findCentroid(int node)
{
    vis[node] = true;
    int centroid = node;

    for(int adj : adjacencies[node])
    {
        if(!vis[adj] && subtreeSize[adj] > n/2)
        {
            centroid = findCentroid(adj);
        }
    }

    return centroid;
}

int computeSubtrees(int node)
{
    vis[node] = true;
    subtreeSize[node] = 1;

    for(int adj : adjacencies[node])
    {
        if(!vis[adj])
        {
            subtreeSize[node] += computeSubtrees(adj);
        }
    }

    return subtreeSize[node];
}

int main() {
    fastio;

    cin >> n;
    adjacencies.resize(n+1);
    vis.resize(n+1, false);
    subtreeSize.resize(n+1, 0);

    for(int i = 0, a, b; i < n-1; i++)
    {
        cin >> a >> b;
        adjacencies[a].push_back(b);
        adjacencies[b].push_back(a);
    }

    computeSubtrees(1);
    fill(vis.begin(), vis.end(), false);
    cout << findCentroid(1) << '\n';
}