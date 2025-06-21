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

int h, w;

bool inbounds(int i, int j) {
    return 0 <= i && i < h && 0 <= j && j < w;
}


int main() {
    fastio;

    cin >> h >> w;

    vector<string> grid(h);

    for(string& line : grid) cin >> line;

    queue<pii> q;
    vector<string> move(h, string(w, '#'));

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(grid[i][j] == 'E') {
                q.emplace(i,j);
                move[i][j] = 'E';
            }
        }
    }

    vector<int> di = {-1,0,1,0}, dj = {0,1,0,-1};

    while(!q.empty()) {
        auto [i,j] = q.front();
        q.pop();

        for(int k = 0; k < 4; k++) {
            int ni = i+di[k];
            int nj = j+dj[k];
            if(inbounds(ni,nj) && move[ni][nj] == '#' && grid[ni][nj] != '#') {
                q.emplace(ni,nj);

                if(k == 0) move[ni][nj] = 'v';
                else if(k == 1) move[ni][nj] = '<';
                else if(k == 2) move[ni][nj] = '^';
                else move[ni][nj] = '>';
            }
        }
    }

    for(string& line : move) cout << line << '\n';
}