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

int h, w, n;
string s;
vector<string> grid;

bool inbounds(int i, int j) {
    return i >= 0 && j >= 0 && i < h && j < w && grid[i][j] != '#';
}

int walk(int i, int j, int move) {
    if(move == n) return 1;
    if(s[move] == 'L' && inbounds(i,j-1)) return walk(i, j-1, move+1);
    if(s[move] == 'U' && inbounds(i-1,j)) return walk(i-1, j, move+1);
    if(s[move] == 'R' && inbounds(i,j+1)) return walk(i, j+1, move+1);
    if(s[move] == 'D' && inbounds(i+1,j)) return walk(i+1, j, move+1);
    return 0;
}

int main() {
    fastio;

    cin >> h >> w >> n;

    cin >> s;

    grid.resize(h);

    for(string& row : grid) cin >> row;

    int count = 0;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(grid[i][j] != '#') count += walk(i, j, 0);
        }
    }

    cout << count << '\n';
}