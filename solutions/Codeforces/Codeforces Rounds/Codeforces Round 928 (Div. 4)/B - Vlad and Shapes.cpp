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

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<string> grid(n);
        for(string& line : grid) cin >> line;

        pii one = {-1,-1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && one.first == -1) {
                    one = {i,j};
                }
            }
        }

        int x = 0, y = 0;

        for(int i = 0; i < n; i++) {
            if(i+one.first == n) break;
            if(grid[one.first+i][one.second] == '1') x++;
        }

        for(int i = 0; i < n; i++) {
            if(i+one.second == n) break;
            if(grid[one.first][one.second+i] == '1') y++;
        }

        if(x == y) cout << "SQUARE\n";
        else cout << "TRIANGLE\n";
    }
}