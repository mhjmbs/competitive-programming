#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

int r, c;
bitset<102> nut;
bitset<102> maze[1001];
bool vis[1001][100];

bitset<102> rot_l(bitset<102> nut) {
    nut[0] = nut[c];
    nut <<= 1;
    nut[c+1] = 0;
    return nut;
}

bitset<102> rot_r(bitset<102> nut) {
    nut[c+1] = nut[1];
    nut >>= 1;
    return nut;
}

bool fits(bitset<102> nut, bitset<102> floor) {

    for(int i = 1; i <= c; i++) {
        if(nut[i] == 1 && floor[i] == 1) return false;
    }
    return true;
}

void backtracking(bitset<102> nut, int floor, int rotation) {
    vis[floor][rotation] = true;
    if(floor == r) {
        cout << "Y\n";
        exit(0);
    }

    bitset<102> curr_nut = nut;

    for(int i = 0, curr_r = rotation; i < c; i++) {
        if(fits(curr_nut, maze[floor+1]) && !vis[floor+1][curr_r]) backtracking(curr_nut, floor+1, curr_r);
        if(fits(rot_l(curr_nut), maze[floor])) {
            curr_nut = rot_l(curr_nut);
            curr_r = ((curr_r - 1) % c + c) % c;
        }else {
            break;
        }
    }

    curr_nut = nut;

    for(int i = 0, curr_r = rotation; i < c; i++) {
        if(fits(curr_nut, maze[floor+1]) && !vis[floor+1][curr_r]) backtracking(curr_nut, floor+1, curr_r);
        if(fits(rot_r(curr_nut), maze[floor])) {
            curr_nut = rot_r(curr_nut);
            curr_r = ((curr_r + 1) % c + c) % c;
        }else {
            break;
        }
    }

    if(floor == 0) return;

    curr_nut = nut;

    for(int i = 0, curr_r = rotation; i < c; i++) {
        if(fits(curr_nut, maze[floor-1]) && !vis[floor-1][curr_r]) backtracking(curr_nut, floor-1, curr_r);
        if(fits(rot_l(curr_nut), maze[floor])) {
            curr_nut = rot_l(curr_nut);
            curr_r = ((curr_r - 1) % c + c) % c;
        }else {
            break;
        }
    }

    curr_nut = nut;

    for(int i = 0, curr_r = rotation; i < c; i++) {
        if(fits(curr_nut, maze[floor-1]) && !vis[floor-1][curr_r]) backtracking(curr_nut, floor-1, curr_r);
        if(fits(rot_r(curr_nut), maze[floor])) {
            curr_nut = rot_r(curr_nut);
            curr_r = ((curr_r + 1) % c + c) % c;
        }else {
            break;
        }
    }
}

int main() {
    fastio;

    cin >> r >> c;

    string nut_s, maze_row;
    
    cin >> nut_s;
    nut = bitset<102>(nut_s);
    nut <<= 1;

    for(int i = 1; i <= r; i++) {
        cin >> maze_row;
        maze[i] = bitset<102>(maze_row);
        maze[i] <<= 1;
    }

    backtracking(nut, 0, 0);

    reverse(nut_s.begin(), nut_s.end());
    nut = bitset<102>(nut_s);
    nut <<= 1;
    for(int i = 0; i <= 1000; i++) {
        for(int j = 0; j < 100; j++) {
            vis[i][j] = false;
        }
    }

    backtracking(nut, 0, 0);

    cout << "N\n";
}