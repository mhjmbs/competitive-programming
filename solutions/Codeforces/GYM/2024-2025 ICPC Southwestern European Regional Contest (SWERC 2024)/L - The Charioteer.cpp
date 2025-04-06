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

int x = 0, y = 0, k = 0;
vector<int> dx = {1,0,-1,0}, dy = {0,-1,0,1};
int v = 1;

int move(char move) {
    if(move == 'R') k = (k+1) % 4;
    else if(move == 'L') k = ((k-1) % 4 + 4) % 4;

    x += v*dx[k];
    y += v*dy[k];
    v++;

    cout << "? " << move << endl;
    int dist;
    cin >> dist;
    return dist;
}

void turnLeft() {
    move('F');
    move('L');
    move('L');
    move('L');
    move('R');
    move('L');
    move('L');
    move('L');
}

void turnRight() {
    move('F');
    move('R');
    move('R');
    move('R');
    move('L');
    move('R');
    move('R');
    move('R');
}

void mod_dec() {
    move('F');
    move('L');
    move('R');
    move('R');
    move('L');
    move('R');
    move('R');
    move('R');
    move('L');
    move('F');
}

void step4() {
    move('F');
    move('L');
    move('L');
    move('L');
    move('L');
    move('R');
    move('R');
    move('R');
}

int main() {
    fastio;

    int d0 = move('F');
    int d = move('F');

    if(d0 - d != v-1) {
        move('F');
        move('F');
        move('F');
        move('F');
        d0 = move('L');
        d = move('L');
    }

    while(d0 - d == v-1) {
        d0 = d;
        d = move('F');
    }

    int X = x + (k == 0 ? -1 : 1)*(d+(v-1)-d0)/2;
    
    d0 = move('R');
    d = move('F'); 
    
    if(d0 - d != v-1) {
        move('F');
        move('F');
        move('F');
        move('F');
        d0 = move('L');
        d = move('L');
    }

    while(d0 - d == v-1) {
        swap(d, d0);
        d = move('F');
    }

    int Y = y + (k == 3 ? -1 : 1)*(d+(v-1)-d0)/2;

    while((X - x) % 4 != 0) {
        while(k != 0) turnLeft();
        mod_dec();
    }

    while((Y - y) % 4 != 0) {
        while(k != 1) turnLeft();
        mod_dec();
    }

    while(x != X) {
        while(x < X && k != 2 || X < x && k != 0) turnRight();
        step4();
    }

    while(y != Y) {
        while(y < Y && k != 1 || Y < y && k != 3) turnRight();
        step4();
    }
}