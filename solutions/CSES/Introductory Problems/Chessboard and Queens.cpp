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

vector<string> grid(8);
vector<vector<int>> blocked(8, vector<int>(8, 0));
int ans = 0;

void backtracking(int i) {
    if(i == 8) {
        ans++;
        return;
    }

    for(int j = 0; j < 8; j++) {
        if(blocked[i][j]) continue;

        for(int k = 0; i+k < 8 && j+k < 8; k++) blocked[i+k][j+k]++;
        for(int k = 0; i+k < 8 && j-k >= 0; k++) blocked[i+k][j-k]++;
        for(int k = i; k < 8; k++) blocked[k][j]++;
    
        backtracking(i+1);

        for(int k = 0; i+k < 8 && j+k < 8; k++) blocked[i+k][j+k]--;
        for(int k = 0; i+k < 8 && j-k >= 0; k++) blocked[i+k][j-k]--;
        for(int k = i; k < 8; k++) blocked[k][j]--;
    }
}

int main() {
    fastio;

    for(string& line : grid) cin >> line;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(grid[i][j] == '*') blocked[i][j]++;
        }
    }

    backtracking(0);

    cout << ans << '\n';
}