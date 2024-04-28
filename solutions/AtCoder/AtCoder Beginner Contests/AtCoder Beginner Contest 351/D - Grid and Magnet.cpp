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

int h, w, dfsCount = 0;
vector<string> grid;
vector<vector<int>> vis;
vector<int> di = {-1,0,1,0}, dj = {0,1,0,-1};

bool inbounds(int i, int j) {
    return 0 <= i && i < h && 0 <= j && j < w;
}

bool isStuck(int i, int j) {
    for(int k = 0; k < 4; k++) {
        int ni = i+di[k], nj = j+dj[k];
        if(inbounds(ni,nj) && grid[ni][nj] == '#') {
            return true;
        }
    }
    return false;
}

int dfs(int i, int j) {
    vis[i][j] = dfsCount;
    int reached = 1;    
    
    if(isStuck(i,j)) { 
        return reached;
    } 

    for(int k = 0; k < 4; k++) {
        int ni = i+di[k], nj = j+dj[k];
        if(inbounds(ni,nj) && grid[ni][nj] != '#' && vis[ni][nj] != dfsCount) {
            reached += dfs(ni,nj);
        } 
    }

    return reached;
}

int main() {
    fastio;

    cin >> h >> w;    
    
    grid.resize(h);
    for(int i = 0; i < h; i++) cin >> grid[i];

    vis.resize(h, vector<int>(w, false));

    int ans = 0;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(!vis[i][j] && grid[i][j] != '#') {
                dfsCount++;
                ans = max(ans, dfs(i,j));                    
            }
        }
    }
    
    cout << ans << '\n';
}
