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

void fill1(int i, int j, vector<string>& grid) {
    grid[i+0][j] = 'I';
    grid[i+1][j] = 'I';
    grid[i+2][j] = 'I';
    grid[i+3][j] = 'I';
    grid[i+4][j] = 'I';
}

void fill2_10(int i, int j, vector<string>& grid) {
    grid[i+0][j+0] = 'L', grid[i+0][j+1] = 'L';
    grid[i+1][j+0] = 'L', grid[i+1][j+1] = 'I';
    grid[i+2][j+0] = 'L', grid[i+2][j+1] = 'I';
    grid[i+3][j+0] = 'L', grid[i+3][j+1] = 'I';
    grid[i+4][j+0] = 'N', grid[i+4][j+1] = 'I';
    grid[i+5][j+0] = 'N', grid[i+5][j+1] = 'I';
    grid[i+6][j+0] = 'N', grid[i+6][j+1] = 'N';
    grid[i+7][j+0] = 'P', grid[i+7][j+1] = 'N';
    grid[i+8][j+0] = 'P', grid[i+8][j+1] = 'P';
    grid[i+9][j+0] = 'P', grid[i+9][j+1] = 'P';
}

void fill2_15(int i, int j, vector<string>& grid) {
    grid[i+0][j+0] = 'L', grid[i+0][j+1] = 'L';
    grid[i+1][j+0] = 'L', grid[i+1][j+1] = 'I';
    grid[i+2][j+0] = 'L', grid[i+2][j+1] = 'I';
    grid[i+3][j+0] = 'L', grid[i+3][j+1] = 'I';
    grid[i+4][j+0] = 'Y', grid[i+4][j+1] = 'I';
    grid[i+5][j+0] = 'Y', grid[i+5][j+1] = 'I';
    grid[i+6][j+0] = 'Y', grid[i+6][j+1] = 'Y';
    grid[i+7][j+0] = 'Y', grid[i+7][j+1] = 'N';
    grid[i+8][j+0] = 'N', grid[i+8][j+1] = 'N';
    grid[i+9][j+0] = 'N', grid[i+9][j+1] = 'Y';
    grid[i+10][j+0] = 'N', grid[i+10][j+1] = 'Y';
    grid[i+11][j+0] = 'Y', grid[i+11][j+1] = 'Y';
    grid[i+12][j+0] = 'P', grid[i+12][j+1] = 'Y';
    grid[i+13][j+0] = 'P', grid[i+13][j+1] = 'P';
    grid[i+14][j+0] = 'P', grid[i+14][j+1] = 'P';
}

void fill3(int i, int j, vector<string>& grid) {
    if(j/3%2==0) {
        grid[i+0][j+0] = 'T', grid[i+0][j+1] = 'T', grid[i+0][j+2] = 'T';
        grid[i+1][j+0] = 'L', grid[i+1][j+1] = 'T', grid[i+1][j+2] = 'Y';
        grid[i+2][j+0] = 'L', grid[i+2][j+1] = 'T', grid[i+2][j+2] = 'Y';
        grid[i+3][j+0] = 'L', grid[i+3][j+1] = 'Y', grid[i+3][j+2] = 'Y';
        grid[i+4][j+0] = 'L', grid[i+4][j+1] = 'L', grid[i+4][j+2] = 'Y';
    }else {
        grid[i+0][j+0] = 'L', grid[i+0][j+1] = 'L', grid[i+0][j+2] = 'Y';
        grid[i+1][j+0] = 'L', grid[i+1][j+1] = 'Y', grid[i+1][j+2] = 'Y';
        grid[i+2][j+0] = 'L', grid[i+2][j+1] = 'T', grid[i+2][j+2] = 'Y';
        grid[i+3][j+0] = 'L', grid[i+3][j+1] = 'T', grid[i+3][j+2] = 'Y';
        grid[i+4][j+0] = 'T', grid[i+4][j+1] = 'T', grid[i+4][j+2] = 'T';
    }
}


void fill4(int i, int j, vector<string>& grid) {
    grid[i+0][j+0] = 'V', grid[i+0][j+1] = 'V', grid[i+0][j+2] = 'V', grid[i+0][j+3] = 'T';
    grid[i+1][j+0] = 'V', grid[i+1][j+1] = 'T', grid[i+1][j+2] = 'T', grid[i+1][j+3] = 'T';
    grid[i+2][j+0] = 'V', grid[i+2][j+1] = 'W', grid[i+2][j+2] = 'W', grid[i+2][j+3] = 'T';
    grid[i+3][j+0] = 'P', grid[i+3][j+1] = 'P', grid[i+3][j+2] = 'W', grid[i+3][j+3] = 'W';
    grid[i+4][j+0] = 'P', grid[i+4][j+1] = 'P', grid[i+4][j+2] = 'P', grid[i+4][j+3] = 'W';
}

void fill5(int i, int j, vector<string>& grid) {
    grid[i+0][j+0] = 'P', grid[i+0][j+1] = 'P', grid[i+0][j+2] = 'V', grid[i+0][j+3] = 'V', grid[i+0][j+4] = 'V';
    grid[i+1][j+0] = 'P', grid[i+1][j+1] = 'P', grid[i+1][j+2] = 'U', grid[i+1][j+3] = 'U', grid[i+1][j+4] = 'V';
    grid[i+2][j+0] = 'P', grid[i+2][j+1] = 'W', grid[i+2][j+2] = 'W', grid[i+2][j+3] = 'U', grid[i+2][j+4] = 'V';
    grid[i+3][j+0] = 'W', grid[i+3][j+1] = 'W', grid[i+3][j+2] = 'U', grid[i+3][j+3] = 'U', grid[i+3][j+4] = 'L';
    grid[i+4][j+0] = 'W', grid[i+4][j+1] = 'L', grid[i+4][j+2] = 'L', grid[i+4][j+3] = 'L', grid[i+4][j+4] = 'L';
}

vector<string> rotate(vector<string>& grid) {
    vector<string> result(grid[0].size(), string(grid.size(), '-'));

    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            result[grid[0].size()-1-j][i] = grid[i][j];
        }
    }

    return result;
}

int main() {
    fastio;

    int oh, ow;
    cin >> oh >> ow;

    if(oh % 5 != 0 && ow % 5 != 0) {
        cout << "no\n";
        return 0;
    }

    int h = oh, w = ow;

    if(h % 5 != 0) swap(h,w);

    vector<string> grid(h, string(w, '-'));

    if(w == 1) {
        if(h == 5) {
            fill1(0,0,grid);
        }else {
            cout << "no\n";
            return 0;
        }
    }else if(w == 2) {
        if(h != 5) {
            for(int i = 0; i+9 < h; i += 10) {
                fill2_10(i,0,grid);
            }
            if(h % 10 != 0) fill2_15(h-15,0,grid);
        }else {
            cout << "no\n";
            return 0;
        }
    }else {
        for(int i = 0; i < h; i += 5) {
            for(int j = 0; j+2 < w; j += 3) {
                fill3(i,j,grid);
            }
        }

        if(w % 3 == 1) {
            for(int i = 0, j = w-4; i < h; i += 5) {
                fill4(i,j,grid);
            }
        }else if(w % 3 == 2) {
            for(int i = 0, j = w-5; i < h; i += 5) {
                fill5(i,j,grid);
            }
        }
    }


    if(oh != h) grid = rotate(grid);

    cout << "yes\n";
    for(string& line : grid) cout << line << '\n';
}
