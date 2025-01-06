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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int h, w;

bool inbounds(int i, int j) {
    return (0 <= i && i < h) && (0 <= j && j < w);
}

int main() {
    fastio;

    cin >> h >> w;

    vector<string> grid(h);

    for(string& line : grid) cin >> line;

    pii s, g;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(grid[i][j] == 'S') s = {i,j};
            if(grid[i][j] == 'G') g = {i,j}; 
        }
    }

    vector<vector<vector<int>>> dp(h, vector<vector<int>>(w, vector<int>(2, 1e9)));

    queue<tiii> q;
    q.push({s.first, s.second, 0});
    q.push({s.first, s.second, 1});
    dp[s.first][s.second][0] = dp[s.first][s.second][1] = 0;

    vector<int> di = {-1,0,1,0}, dj = {0,1,0,-1};

    while(!q.empty()) {
        auto [i,j,dir] = q.front();
        q.pop();

        for(int k = 0; k < 4; k++) {
            if(dir == 0 && (k == 0 || k == 2) || dir == 1 && (k == 1 || k == 3)) continue;
            int ni = i+di[k];
            int nj = j+dj[k];
        
            if(inbounds(ni,nj) && dp[ni][nj][!dir] == 1e9 && grid[ni][nj] != '#') {
                q.emplace(ni,nj,!dir);
                dp[ni][nj][!dir] = dp[i][j][dir]+1;
            }
        }
    }

    int ans = min(dp[g.first][g.second][0], dp[g.first][g.second][1]);

    cout << (ans != 1e9 ? ans : -1) << '\n';
}