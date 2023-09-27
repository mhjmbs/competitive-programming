#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adjacencies(n+1);

    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        adjacencies[a].push_back(b);
        adjacencies[b].push_back(a);
    }
    
    vector<int> p(n+1, -1);
    vector<bool> vis(n+1, false);
    queue<int> q;

    q.push(1);
    vis[1] = true;
    
    while(!q.empty()) {
        int c = q.front();
        q.pop();

        if(c == n) {
            break;
        }

        for(int adj : adjacencies[c]) {
            if(!vis[adj]) {
                q.push(adj);
                p[adj] = c;
                vis[adj] = true;
            }
        }
    }

    stack<int> path;

    int curr = n;

    while(curr != -1) {
        path.push(curr);
        curr = p[curr];
    }

    if(path.size() == 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << path.size() << '\n';

    while(!path.empty()) {
        cout << path.top();
        path.pop();
        if(path.size() > 0) cout << ' ';
        else cout << '\n';
    }
}
