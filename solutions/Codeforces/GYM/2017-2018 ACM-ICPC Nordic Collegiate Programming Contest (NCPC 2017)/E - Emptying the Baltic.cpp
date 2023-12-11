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
using pip = pair<int,pii>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;



int main() {
    fastio;

    int h, w;
    cin >> h >> w;

    vector<vector<int>> depth(h, vector<int>(w));
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> depth[i][j];
        }
    }

    pii source;
    cin >> source.first >> source.second;
    source.first--; source.second--;

    priority_queue<pip, vector<pip>, greater<pip>> prioq;
    vector<vector<bool>> vis(h, vector<bool>(w, false));
    prioq.emplace(depth[source.first][source.second], source);
    vis[source.first][source.second] = true;

    vector<int> di = {-1,-1,-1,0,1,1,1,0}, dj = {-1,0,1,1,1,0,-1,-1};

    ll ans = 0;

    while(!prioq.empty())
    {
        int currDepth = prioq.top().first;
        auto [i,j] = prioq.top().second;
        prioq.pop();
        ans += -currDepth;

        for(int k = 0; k < 8; k++)
        {
            int ni = i+di[k];
            int nj = j+dj[k];

            if(ni < 0 || nj < 0 || ni >= h || nj >= w || vis[ni][nj])
            {
                continue;
            }

            if(depth[ni][nj] < 0)
            {
                prioq.emplace(max(currDepth, depth[ni][nj]), make_pair(ni,nj));
                vis[ni][nj] = true;
            }
        }
    }

    cout << ans << '\n';
}