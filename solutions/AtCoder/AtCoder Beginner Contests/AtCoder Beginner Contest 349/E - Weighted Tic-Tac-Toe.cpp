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

ll grid[10];
int color[10];
ll score[3];

bool hasWinnerColor(int player) {
    return
    color[1] == player && color[1] == color[2] && color[2] == color[3] ||
    color[4] == player && color[4] == color[5] && color[5] == color[6] ||
    color[7] == player && color[7] == color[8] && color[8] == color[9] ||
    color[1] == player && color[1] == color[4] && color[4] == color[7] ||
    color[2] == player && color[2] == color[5] && color[5] == color[8] ||
    color[3] == player && color[3] == color[6] && color[6] == color[9] ||
    color[1] == player && color[1] == color[5] && color[5] == color[9] ||
    color[3] == player && color[3] == color[5] && color[5] == color[7];
}

bool gameEnd() {
    bool ans = true;
    for(int i = 1; i <= 9; i++) {
        if(color[i] == 0) ans = false;
    }
    return ans;
}

bool isWinning(int player) {
    if(hasWinnerColor(player) || gameEnd() && score[player] > score[player == 1 ? 2 : 1]) {
        return true;
    }

    bool ans = false;

    for(int i = 1; i <= 9; i++) {
        if(color[i] != 0) continue;
        color[i] = player;
        score[player] += grid[i];
        ans = ans || !isWinning(player == 1 ? 2 : 1);
        color[i] = 0;
        score[player] -= grid[i];
    }

    return ans;
}

int main() {
    fastio;

    for(int i = 1; i <= 9; i++) cin >> grid[i];

    if(isWinning(1)) cout << "Takahashi\n";
    else cout << "Aoki\n";
}