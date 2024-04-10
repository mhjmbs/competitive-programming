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



int main() {
    fastio;

    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    for(string& s : grid) cin >> s;

    int n;
    cin >> n;
    vector<vector<int>> med(h, vector<int>(w, -1));
    for(int i = 0; i < n; i++) {
        int ri, ci, ei;
        cin >> ri >> ci >> ei;
        ri--,ci--;
        med[ri][ci] = ei;
    }

    vector<vector<int>> dp(h, vector<int>(w, -1));

    int si, sj, ti, tj;
    for(int i = 0; i < h; i++) {
        if(grid[i].find('S') < w) {
            si = i;
            sj = grid[i].find('S');
        }
        if(grid[i].find('T') < w) {
            ti = i;
            tj = grid[i].find('T');
        }
    }

    queue<tiii> q;
    q.emplace(si, sj, 0);

    int di[] = {0,1,0,-1}, dj[] = {1,0,-1,0};

    while(!q.empty()) {
        auto [i,j,hp] = q.front();
        q.pop();

        if(med[i][j] > hp) {
            hp = med[i][j];
            dp[i][j] = hp;
        }

        for(int k = 0; k < 4; k++) {
            int ni = i+di[k];
            int nj = j+dj[k];

            if(0 <= ni && ni < h && 0 <= nj && nj < w && grid[ni][nj] != '#' && dp[ni][nj] < hp-1) {
                dp[ni][nj] = hp-1;
                q.emplace(ni,nj,dp[ni][nj]);
            }
        }
    }

    if(dp[ti][tj] >= 0) cout << "Yes\n";
    else cout << "No\n";
}