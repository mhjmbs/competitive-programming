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

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> answer(n, vector<int>(m)), grid(n, vector<int>(m));
        
        for(int i = 0, curr = 1; i < n; i++) {
            for(int j = 0; j < m; j++,curr++) {
                grid[i][j] = curr;
            }
        }

        int a_i = 0, a_j = 0;
        for(int i = 1; i < n; i+=2) {
            for(int j = 0; j < m; j++,a_j++) {
                answer[a_i][a_j] = grid[i][j];
            }
            a_j = 0;
            a_i++;
        }
        for(int i = 0; i < n; i+=2) {
            for(int j = 0; j < m; j++,a_j++) {
                answer[a_i][a_j] = grid[i][j];
            }
            a_j = 0;
            a_i++;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << answer[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}