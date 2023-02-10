#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n, m, p, b;
        cin >> n >> m >> p >> b;

        vector<bool> hasToken(n, false);
        for(int i = 0, inp; i < p; i++) {
            cin >> inp;
            inp--;
            hasToken[inp] = true;
        }

        vector<int> hasBonus(n, false);
        for(int i = 0, inp; i < b; i++) {
            cin >> inp;
            inp--;
            hasBonus[inp] = true;
        }

        vector<vector<int>> adjacencies(n);
        for(int i = 0, u, v; i < m; i++) {
            cin >> u >> v;
            u--; v--;
            adjacencies[u].push_back(v);
            adjacencies[v].push_back(u);
        }

        vector<bool> vis(n, false);
        queue<pii> q;
        q.emplace(0,0);
        vis[0] = true;

        pii winner = {-1,-1};

        while(!q.empty()) {
            int node = q.front().first;
            int d = q.front().second;
            q.pop();

            if(hasToken[node]) {
                winner = {node, d};
                break;
            }

            for(int adj : adjacencies[node]) {
                if(!vis[adj] && (hasBonus[adj] || hasToken[adj])) {
                    q.emplace(adj, d+1);
                    vis[adj] = true;
                }
            }
        }

        if(winner == make_pair(-1,-1)) {
            cout << "NO\n";
            continue;
        }

        bool yes = false;

        int poss_moves = 1;
        for(int i = 0; i < n; i++) {
            int max_moves = 0;

            if(hasToken[i] && i != winner.first) {
                queue<pii> q;
                q.emplace(i, 0);

                while(!q.empty()) {
                    int node = q.front().first;
                    int d = q.front().second;
                    q.pop();

                    max_moves = max(max_moves, d);

                    if(d >= 2) {
                        max_moves = int(1e7);
                        break;
                    }

                    for(int adj : adjacencies[node]) {
                        if(hasBonus[adj]) q.emplace(adj, d+1);
                    }
                }
            }

            poss_moves += max_moves;

            if(poss_moves >= winner.second) {
                yes = true;
                break;
            }
        }

        if(yes) cout << "YES\n";
        else cout << "NO\n";
    }
}