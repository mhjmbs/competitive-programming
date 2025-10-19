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

int n;
vector<string> grid;

bool inbounds(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < n;
}

bool can(int i, int j) {
    for(int ci = i-1; ci <= i+1; ci++) {
        for(int cj = j-1; cj <= j+1; cj++) {
            if(inbounds(ci,cj) && grid[ci][cj] == '#') return false;
        }
    }
    return inbounds(i,j);
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        cin >> n;

        if(n == 1) {
            cout << ".\n";
            continue;
        }

        grid = vector<string>(n, string(n,'.'));

        for(int i = 0; i < n; i+=2) {
            for(int j = 0; j < n-1; j+=3) {
                grid[i][j] = grid[i][j+1] = '#';
            }
        }
        
        
        int ri = (grid[n-1][0] == '.');
        int rj = (grid[0][n-1] == '.') + (grid[0][n-2] == '.');
        
        if(ri == 0 && rj == 1) {
            for(int i = 0, up = 0; i < n-2; up = !up) {
                if(!up) {
                    if(grid[i].substr(n-3,3) == "##." && grid[i+2].substr(n-3,3) == "##.") {
                        grid[i][n-2] = grid[i+2][n-3] = grid[i+2][n-2] = '.';
                        grid[i+1][n-3] = grid[i][n-1] = grid[i+1][n-1] = '#';
                    }
                    i += 4;
                }else {
                    if(grid[i].substr(n-3,3) == "##." && grid[i+2].substr(n-3,3) == "##.") {
                        grid[i][n-2] = '.';
                        //grid[i+2][n-3] = grid[i+2][n-2] = '.';
                        grid[i-1][n-3] = grid[i-1][n-1] = grid[i][n-1] = '#';
                    }
                    i += 2;
                }
            }
        }
        
        if(ri == 0 && rj == 2) {
            for(int i = 0; i < n-1; i+=3) {
                grid[i][n-1] = grid[i+1][n-1] = '#';
            }
        }
        
        if(ri == 1 && rj == 0) {
            for(int j = 0; j < n; j++) grid[n-2][j] = '.';
            for(int j = 0; j < n; j+=2) {
                grid[n-2][j] = grid[n-1][j] = '#';
            }
        }
        
        if(ri == 1 && rj == 1) {

            for(int i = 0, up = 0; i < n-2; up = !up) {
                if(!up) {
                    if(grid[i].substr(n-3,3) == "##." && grid[i+2].substr(n-3,3) == "##.") {
                        grid[i][n-2] = grid[i+2][n-3] = grid[i+2][n-2] = '.';
                        grid[i+1][n-3] = grid[i][n-1] = grid[i+1][n-1] = '#';
                    }
                    i += 4;
                }else {
                    if(grid[i].substr(n-3,3) == "##." && grid[i+2].substr(n-3,3) == "##.") {
                        grid[i][n-2] = '.';
                        //grid[i+2][n-3] = grid[i+2][n-2] = '.';
                        grid[i-1][n-3] = grid[i-1][n-1] = grid[i][n-1] = '#';
                    }
                    i += 2;
                }
            }
            
            int mx = grid[n-2][n-2] == '#' ? n : n-4;
            
            for(int j = 0; j < mx; j++) grid[n-2][j] = '.';
            for(int j = 0; j < mx; j+=2) {
                grid[n-2][j] = grid[n-1][j] = '#';
            }
            
            if(mx != n) {
                grid[n-1][n-2] = grid[n-1][n-1] = '#';
            }else {
                swap(grid[n-1][n-1], grid[n-2][n-2]);
                if(can(n-3,n-1) && can(n-3,n-2)) {
                    grid[n-3][n-1] = grid[n-3][n-2] = '#';
                }
            }
        }
        
        if(ri == 1 && rj == 2) {
            for(int j = 0; j < n; j++) grid[n-2][j] = '.';
            for(int j = 0; j < n; j+=2) {
                grid[n-2][j] = grid[n-1][j] = '#';
            }
            
            for(int i = 0; i < n-1; i+=3) {
                grid[i][n-1] = grid[i+1][n-1] = '#';
            }
            
            if(grid[n-2][n-2] == '#') {
                swap(grid[n-2][n-2], grid[n-1][n-1]);
            }
        }

        for(auto& line : grid) cout << line << '\n';
    }
}