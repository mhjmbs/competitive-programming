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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int h, w;
vector<vector<ll>> grid, filled;
ll ans = -1;

bool inbounds(int i, int j) {
    return 1 <= i && i <= h && 1 <= j && j <= w;
}

void backtracking(int i, int j) {
    if(i == h+1) {
        ll curr = 0;
        for(int i = 1; i <= h; i++) {
            for(int j = 1; j <= w; j++) {
                if(!filled[i][j]) curr ^= grid[i][j];
            }
        }
        ans = max(ans, curr);
        return;
    }

    int ni = inbounds(i,j+1) ? i : i+1;
    int nj = inbounds(i,j+1) ? j+1 : 1;

    backtracking(ni, nj);

    if(inbounds(i,j+1) && !filled[i][j] && !filled[i][j+1]) {
        filled[i][j] = filled[i][j+1] = true;
        backtracking(ni, nj);
        filled[i][j] = filled[i][j+1] = false;
    }

    if(inbounds(i+1,j) && !filled[i][j] && !filled[i+1][j]) {
        filled[i][j] = filled[i+1][j] = true;
        backtracking(ni, nj);
        filled[i][j] = filled[i+1][j] = false;
    }
}

int main() {
    fastio;
 
    cin >> h >> w;
    grid.resize(h+1, vector<ll>(w+1));

    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            cin >> grid[i][j];
        }
    }

    filled.resize(h+1, vector<ll>(w+1));

    backtracking(1, 1);

    cout << ans << '\n';
}