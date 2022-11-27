#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(0);

    int n, m;

    cin >> n >> m;

    vector<string> grid(n);

    for(string& line : grid) {
        cin >> line;
    }

    pii a, b;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'A') a = make_pair(i,j);
            if(grid[i][j] == 'B') b = make_pair(i,j);
        }
    }

    vector<vector<int>> d(n, vector<int>(m, INT_MAX));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<int> di = {0,1,0,-1}, dj = {1,0,-1,0};
    vector<vector<char>> lm(n, vector<char>(m, 'x'));
    queue<pii> q;
    
    q.push(a);
    d[a.first][a.second] = 0;
    vis[a.first][a.second] = true;

    while(!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if(grid[i][j] == 'B') {
            break;
        }

        for(int counter = 0; counter < 4; counter++) {
            int ni = i + di[counter];
            int nj = j + dj[counter];
            int cm;
            switch(counter) {
                case 0: {
                    cm = 'R';
                    break;
                }
                case 1: {
                    cm = 'D';
                    break;
                }
                case 2: {
                    cm = 'L';
                    break;
                }
                default:
                    cm = 'U';
            }

            if(0 <= ni && ni < n && 0 <= nj && nj < m &&
               grid[ni][nj] != '#' && !vis[ni][nj]) {
                q.emplace(ni,nj);
                vis[ni][nj] = true;
                lm[ni][nj] = cm;
            }
        }
    }

    if(lm[b.first][b.second] == 'x') {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    int i = b.first;
    int j = b.second;

    stack<char> path;
    while(i != a.first || j != a.second) {
        char clm = lm[i][j];
        path.push(clm);

        if(clm == 'R') j--;
        else if(clm == 'D') i--;
        else if(clm == 'L') j++;
        else i++;
    }
    
    cout << path.size() << '\n';
    while(!path.empty()) {
        cout << path.top();
        path.pop();
    }
    cout << '\n';
}
