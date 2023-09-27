#include "bits/stdc++.h"

using namespace std;
using pii = pair<int,int>;
using ppi = pair<pii,int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    for(int i = 0; i < n; i++) cin >> grid[i];

    queue<ppi> q;
    pii A;
    vector<vector<bool>> vis(n, vector<bool>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'M') {
                q.emplace(make_pair(i, j), 0);
                vis[i][j] = true;
            }else if(grid[i][j] == 'A') A = {i, j};
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, int(1e9)));
    vector<int> di = {0,1,0,-1}, dj = {1,0,-1,0};

    while(!q.empty()) {
        int i = q.front().first.first;
        int j = q.front().first.second;
        int d = q.front().second;
        q.pop();

        dist[i][j] = d;

        for(int k = 0; k < 4; k++) {
            int ni = i+di[k], nj = j+dj[k];

            if(0 <= ni && ni < n && 0 <= nj && nj < m
            && !vis[ni][nj] && grid[ni][nj] != '#') {
                vis[ni][nj] = true;
                q.emplace(make_pair(ni,nj), d+1);
            }
        }
    }

    for(auto &col : vis) {
        fill(col.begin(), col.end(), false);
    }

    q.emplace(A, 0);
    vis[A.first][A.second] = true;

    bool yes = false;
    ppi end;

    vector<vector<char>> last(n, vector<char>(m));
    last[A.first][A.second] = '-';

    while(!q.empty()) {
        int i = q.front().first.first;
        int j = q.front().first.second;
        int d = q.front().second;
        q.pop();

        if(dist[i][j] <= d) continue;

        if(i == 0 || i == n-1
        || j == 0 || j == m-1) {
            yes = true;
            end = {make_pair(i, j), d};
            break;
        }

        for(int k = 0; k < 4; k++) {
            int ni = i+di[k], nj = j+dj[k];

            if(0 <= ni && ni < n && 0 <= nj && nj < m
            && !vis[ni][nj] && grid[ni][nj] != '#') {
                vis[ni][nj] = true;
                q.emplace(make_pair(ni,nj), d+1);

                if(k == 0) last[ni][nj] = 'R';
                else if(k == 1) last[ni][nj] = 'D';
                else if(k == 2) last[ni][nj] = 'L';
                else last[ni][nj] = 'U';
            }
        }
    }

    if(yes) {
        cout << "YES\n";
        cout << end.second << '\n';

        int i = end.first.first, j = end.first.second;

        stack<char> ans;

        while(last[i][j] != '-') {
            char curr = last[i][j];
            ans.push(curr);
            if(curr == 'R') j--;
            else if(curr == 'D') i--;
            else if(curr == 'L') j++;
            else i++;
        }

        while(!ans.empty()) {
            cout << ans.top();
            ans.pop();
        }
        cout << '\n';
    }else {
        cout << "NO\n";
    }
}