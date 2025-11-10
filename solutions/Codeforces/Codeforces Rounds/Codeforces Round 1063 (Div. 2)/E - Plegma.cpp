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

void first() {
    int t;
    cin >> t;

    while(t--) {
        int n, c;
        cin >> n >> c;
        
        vector<string> grid(n);
        for(string& line : grid) cin >> line;

        int row = -1, col = -1;

        if(c) {
            for(int i = 0; i < n; i++) {
                if(grid[i][0] == '0') row = i;
            }
            if(row == -1) {
                row = col = 0;
            }else {
                for(int i = 0; i < n; i++) {
                    int curr = find(grid[i].begin(), grid[i].end(), '1') - grid[i].begin();
                    if(curr != n) col = curr;
                }
            }
        }else {
            for(int i = 0; i < n; i++) {
                if(grid[i][0] == '1') row = i;
            }
            if(row == -1) {
                row = col = 0;
            }else {
                for(int i = 0; i < n; i++) {
                    int curr = find(grid[i].begin(), grid[i].end(), '0') - grid[i].begin();
                    if(curr != n) col = curr;
                }
            }
        }

        cout << row+1 << ' ' << col+1 << '\n';
    }
}

void second() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string row, col;
        cin >> row >> col; 

        if(all_of(col.begin(), col.end(), [&row](char c) {
            return c == row[0];
        })) {
            cout << row[0] << '\n';
        }else {
            cout << (row[0] == '1' ? 0 : 1) << '\n';
        }
    }
}

int main() {
    fastio;

    string run;
    cin >> run;

    if(run == "first") first();
    else second();
}