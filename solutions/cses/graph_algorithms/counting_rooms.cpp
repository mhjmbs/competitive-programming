#include "bits/stdc++.h"

using namespace std;

int n, m;
vector<string> grid(n);
vector<vector<bool>> vis;

vector<int> di = {0,1,0,-1}, dj = {1,0,-1,0};

void dfs(int x, int y) {
    vis[x][y] = true;

    for(int k = 0; k < 4; k++) {
        int nx = x + di[k];
        int ny = y + dj[k];

        if(0 <= nx && nx < n && 0 <= ny && ny < m &&
            grid[nx][ny] == '.' && !vis[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);

    cin >> n >> m;

    grid.resize(n);
    vis.resize(n, vector<bool>(m, false));

    for(string& line : grid) {
        cin >> line;
    }

    int roomCount = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '.' && !vis[i][j]) {
                roomCount++;
                dfs(i, j);
            }
        }
    }

    cout << roomCount << '\n';
}