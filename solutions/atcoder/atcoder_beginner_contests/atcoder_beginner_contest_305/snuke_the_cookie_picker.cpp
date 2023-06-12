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



int main() {
    fastio;

    int h, w;
    cin >> h >> w;

    vector<vector<char>> grid(h+1, vector<char>(w+1));

    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            cin >> grid[i][j];
        }
    }

    int last_s = -1, last_e = -1;
    pii ans;

    for(int i = 1; i <= h; i++) {
        int start = -1, end = -1;

        for(int j = 1; j <= w; j++) {
            if(grid[i][j] == '#') {
                if(start == -1) start = j;
                end = j;
            }else if(end != -1) {
                break;
            }
        }

        if(last_s != -1 && start != -1) {
            if(last_s > start) {
                ans = {i-1, last_s-1};
            }else if(last_s < start) {
                ans = {i, start-1};
            }else if(last_e < end) {
                ans = {i-1, last_e+1};
            }else if(last_e > end) {
                ans = {i, end+1};
            }
        }

        last_s = start;
        last_e = end;
    }

    cout << ans.first << ' ' << ans.second << '\n';
}