#include "bits/stdc++.h"

using namespace std;
using tiii = tuple<int,int,int>;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> distFrom1(n, vector<int>(m, INT_MAX));
    vector<vector<int>> distFrom2(n, vector<int>(m, INT_MAX));
    vector<vector<int>> distFrom3(n, vector<int>(m, INT_MAX));
    vector<vector<ll>> minDist(4, vector<ll>(4, INT_MAX));
    vector<int> di = {0,1,0,-1}, dj = {1,0,-1,0};

    for(int state = 1; state <= 3; state++) {
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<tiii> q;

        //Inicializando vis e q para multi-source bfs
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == state + '0') {
                    if(state == 1) distFrom1[i][j] = 0;
                    else if(state == 2) distFrom2[i][j] = 0;
                    else distFrom3[i][j] = 0;

                    vis[i][j] = true;
                    q.emplace(i, j, 0);
                }
            }
        }

        //Multi-source bfs
        while(!q.empty()) {
            int ci = get<0>(q.front()), cj = get<1>(q.front()), dist = get<2>(q.front());

            if(grid[ci][cj] != '.') {
                minDist[state][grid[ci][cj]-'0'] = min(minDist[state][grid[ci][cj]-'0'], ll(dist)-1);
            }else {
                if(state == 1) distFrom1[ci][cj] = dist-1;
                else if(state == 2) distFrom2[ci][cj] = dist-1;
                else distFrom3[ci][cj] = dist-1;
            }

            for(int k = 0; k < 4; k++) {
                if(0 <= ci+di[k] && ci+di[k] < n &&
                0 <= cj+dj[k] && cj+dj[k] < m &&
                grid[ci+di[k]][cj+dj[k]] != '#' &&
                !vis[ci+di[k]][cj+dj[k]]) {
                    q.emplace(ci+di[k], cj+dj[k], dist + 1);
                    vis[ci+di[k]][cj+dj[k]] = true;
                }
            }

            q.pop();
        }
    }

    ll ans = min({minDist[1][2] + minDist[1][3], minDist[2][1] + minDist[2][3], minDist[3][1] + minDist[3][2]});

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '.') {
                ans = min(ans, ll(distFrom1[i][j]) + distFrom2[i][j] + distFrom3[i][j] + 1);
            }
        }
    }

    if(ans >= INT_MAX) cout << -1 << '\n';
    else cout << ans << '\n';
}