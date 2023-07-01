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

    int h, w;
    cin >> h >> w;

    vector<string> grid(h);

    for(string &s : grid) cin >> s;

    map<char,char> next = {
        {'s','n'},
        {'n','u'},
        {'u','k'},
        {'k','e'},
        {'e','s'}
    };

    vector<int> di = {0,1,0,-1}, dj = {1,0,-1,0};

    queue<pii> q;
    vector<vector<bool>> vis(h, vector<bool>(w));
    
    if(grid[0][0] == 's') {
        q.emplace(0,0);
        vis[0][0] = true;
    }

    while(!q.empty()) {
        int i, j;
        tie(i,j) = q.front();
        q.pop();

        for(int k = 0; k < 4; k++) {
            int ni = i+di[k], nj = j+dj[k];

            if(0 <= ni && ni < h && 0 <= nj && nj < w &&
            grid[ni][nj] == next[grid[i][j]] && !vis[ni][nj]) {
                vis[ni][nj] = true;
                q.emplace(ni,nj);
            }
        }
    }
    
    if(vis[h-1][w-1]) {
        cout << "Yes\n";
    }else {
        cout << "No\n";
    }
}