#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

vector<vector<int>> adjacencies, inv_adjacencies;

int main() {
    fastio;

    int n;
    cin >> n;

    adjacencies.resize(n+1);
    inv_adjacencies.resize(n+1);

    for(int i = 1, xi, yi; i <= n; i++) {
        cin >> xi >> yi;
        adjacencies[i].insert(adjacencies[i].end(), {xi, yi});
        inv_adjacencies[xi].push_back(i);
        inv_adjacencies[yi].push_back(i);
    }

    for(int i = 1; i <= n; i++) {
        int xi = adjacencies[i][0], yi = adjacencies[i][1];

        set<int> reachable;

        vector<bool> vis(n+1);
        queue<int> q;
        q.push(xi);
        vis[xi] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            reachable.insert(node);

            for(int adj : inv_adjacencies[node]) {
                if(!vis[adj] && adj != i) {
                    q.push(adj);
                    vis[adj] = true;
                }
            }
        }

        fill(vis.begin(), vis.end(), false);
        q.push(yi);
        vis[yi] = true;

        set<int> reachable2;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            if(reachable.count(node) == 1) reachable2.insert(node);

            for(int adj : inv_adjacencies[node]) {
                if(!vis[adj] && adj != i) {
                    q.push(adj);
                    vis[adj] = true;
                }
            }
        }

        fill(vis.begin(), vis.end(), false);
        q.push(i);
        vis[i] = true;

        set<int> reachable3;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            if(reachable2.count(node) == 1) reachable3.insert(node);

            for(int adj : inv_adjacencies[node]) {
                if(!vis[adj]) {
                    q.push(adj);
                    vis[adj] = true;
                }
            }
        }

        if(!reachable3.empty()) cout << 'Y';
        else cout << 'N';

    }
    cout << '\n';
}