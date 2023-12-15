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

queue<pair<pii,int>> q;
vector<vector<bool>> enqueued;
vector<vector<int>> dist;
vector<vector<char>> lastMove;
vector<int> di = {0, 1, 0, -1}, dj = {1, 0, -1, 0};

pii getCoord(char c) {
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[i].size(); j++) {
            if(grid[i][j] == c) return {i,j};
        }
    }
}

bool inbounds(int i, int j) {
    return (0 <= i && i < n) && (0 <= j && j < m);
}

int main() {
    fastio;

    cin >> n >> m;

    grid.resize(n);
    for(string& line : grid) cin >> line;

    pii A = getCoord('A');
    pii B = getCoord('B');

    enqueued.resize(n, vector<bool>(m, false));
    dist.resize(n, vector<int>(m, -1));
    lastMove.resize(n, vector<char>(m));

    dist[A.first][A.second] = 0;
    q.emplace(A, 0);
    enqueued[A.first][A.second] = true;

    while(!q.empty()) {
        auto [i,j] = q.front().first;
        int currDist = q.front().second;
        q.pop();
        
        dist[i][j] = currDist;

        for(int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];

            if(inbounds(ni, nj) && grid[i][j] != '#' && !enqueued[ni][nj]) {
                q.emplace(make_pair(ni,nj), currDist+1);
                enqueued[ni][nj] = true;

                if(k == 0) lastMove[ni][nj] = 'R';
                else if(k == 1) lastMove[ni][nj] = 'D';
                else if(k == 2) lastMove[ni][nj] = 'L';
                else  lastMove[ni][nj] = 'U';
            }
        }
    }

    if(dist[B.first][B.second] == -1) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    cout << dist[B.first][B.second] << '\n';

    string path;
    pii curr = B;

    while(curr != A) {
        char move = lastMove[curr.first][curr.second];
        path.push_back(move);

        if(move == 'R') curr.second--;
        else if(move == 'D') curr.first--;
        else if(move == 'L') curr.second++;
        else if(move == 'U') curr.first++;
    }

    reverse(path.begin(), path.end());
    
    cout << path << '\n';
}