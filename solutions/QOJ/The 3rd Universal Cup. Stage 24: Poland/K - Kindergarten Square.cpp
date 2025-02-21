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



int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        vector<vector<int>> square(2, vector<int>(2));
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                cin >> square[i][j];
            }
        }

        int w = square[1][0] - square[0][0];
        int h = 100000;

        vector<vector<int>> square2(2, vector<int>(2,-1));
        square2[0][0] = square[0][0]; 

        if(w > 0 && square[0][0]%w != 0) {
            square2[0][1] = square2[0][0]+1;
            square2[1][0] = square2[0][0]+w;
            square2[1][1] = square2[0][0]+w+1;
        }

        if(square == square2) cout << h << ' ' << w << '\n';
        else cout << -1 << '\n';
    }
}
