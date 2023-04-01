#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

int di[4] = {0,1,0,-1}, dj[4] = {1,0,-1,0};

int main() {
    fastio;

    int r, c;
    cin >> r >> c;

    vector<vector<int>> grid(r, vector<int>(c));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) cin >> grid[i][j];
    }

    int ans = 0;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            priority_queue<tiii, vector<tiii>, greater<tiii>> prioq;
            vector<vector<bool>> vis(r, vector<bool>(c, false));

            prioq.emplace(grid[i][j], i, j);
            vis[i][j] = true;
            
            int max_computed = 0, curr_ans = 0;

            while(!prioq.empty()) {
                int curr, ci, cj;
                tie(curr, ci, cj) = prioq.top();
                prioq.pop();

                if(curr <= max_computed) continue;
                max_computed = curr;
                curr_ans++;

                for(int k = 0; k < 4; k++) {
                    int ni = ci + di[k], nj = cj+dj[k];
                    if(0 <= ni && ni < r
                    && 0 <= nj && nj < c
                    && !vis[ni][nj] && max_computed < grid[ni][nj]) {
                        prioq.emplace(grid[ni][nj], ni, nj);
                        vis[ni][nj] = true;
                    }
                }
            }

            ans = max(ans, curr_ans);
        }
    }

    cout << ans << '\n';
}