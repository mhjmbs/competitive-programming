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
vector<string> grid;
vector<vector<bool>> vis;
vector<int> di = {0,1,0,-1}, dj = {1,0,-1,0};

bool inbounds(int i, int j) {
    return (0 <= i && i < n) && (0 <= j && j < m);
}

void dfs(int i, int j) {
    vis[i][j] = true;

    for(int k = 0; k < 4; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if(inbounds(ni,nj) && grid[ni][nj] != '#' && !vis[ni][nj]) {
            dfs(ni,nj);
        }
    }
}

int main() {
    fastio;

    cin >> n >> m;

    grid.resize(n);
    vis.resize(n, vector<bool>(m, false));

    for(string& line : grid) cin >> line;
    
    int cc = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] != '#' && !vis[i][j]) {
                cc++;
                dfs(i,j);
            }
        }
    }

    cout << cc << '\n';
}