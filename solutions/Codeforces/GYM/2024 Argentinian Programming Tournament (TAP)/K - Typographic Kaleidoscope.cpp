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

vector<vector<int>> vis;

void visit_t(int i, int j) {
    vis[i+0][j-2] = vis[i+0][j-1] = vis[i+0][j-0] =
                    vis[i+1][j-1]                 =
                    vis[i+2][j-1]                 =
                    vis[i+3][j-1]                 =
                    vis[i+4][j-1]                 = true;
}

void visit_a(int i, int j) {
    vis[i+0][j-2] = vis[i+0][j-1] = vis[i+0][j-0] =
    vis[i+1][j-2] =                 vis[i+1][j-0] =
    vis[i+2][j-2] = vis[i+2][j-1] = vis[i+2][j-0] =
    vis[i+3][j-2] =                 vis[i+3][j-0] =
    vis[i+4][j-2] =                 vis[i+4][j-0] = true;
}

void visit_p(int i, int j) {
    vis[i+0][j-2] = vis[i+0][j-1] = vis[i+0][j-0] =
    vis[i+1][j-2] =                 vis[i+1][j-0] =
    vis[i+2][j-2] = vis[i+2][j-1] = vis[i+2][j-0] =
    vis[i+3][j-2]                                 =
    vis[i+4][j-2]                                 = true;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    vis.resize(n, vector<int>(m, false));

    for(string& row : grid) cin >> row;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '.') vis[i][j] = true;
        }
    }

    int t = 0, a = 0, p = 0;

    for(int j = m-1; j >= 2; j--) {
        for(int i = 0; i < n-4; i++) {
            if(!vis[i][j]) {
                if(vis[i+1][j]) {
                    visit_t(i, j);
                    t++;
                }else if(!vis[i+3][j]) {
                    visit_a(i,j);
                    a++;
                }else {
                    visit_p(i,j);
                    p++;
                }
            }
        }
    }

    cout << t << ' ' << a << ' ' << p << '\n';
}