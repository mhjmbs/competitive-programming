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

string s;
bool vis[9][9];
int k[48], di[] = {0,1,0,-1}, dj[] = {1,0,-1,0};
 
int backtracking(int i, int j, int count) {
    if(i == 7 && j == 1) {
        if(count == 48) return 1;
        return 0;
    }
 
    if(!vis[i-1][j] && !vis[i+1][j] && vis[i][j-1] && vis[i][j+1] ||
       vis[i-1][j] && vis[i+1][j] && !vis[i][j-1] && !vis[i][j+1]) {
        return 0;
    }

    vis[i][j] = true;
    int ans = 0;
 
    if(k[count] == 4) {
        for(int l = 0; l < 4; l++) {
            int ni = i+di[l];
            int nj = j+dj[l];
    
            if(!vis[ni][nj]) {
                ans += backtracking(ni, nj, count+1);
            }
        }
    }else {
        int ni = i+di[k[count]];
        int nj = j+dj[k[count]];

        if(!vis[ni][nj]) {
            ans += backtracking(ni, nj, count+1);
        }
    }

    vis[i][j] = false;
    return ans;
}
 
int main() {
    fastio;
 
    cin >> s;

    for(int i = 0; i < 48; i++) {
        if(s[i] == 'R') k[i] = 0;
        else if(s[i] == 'D') k[i] = 1;
        else if(s[i] == 'L') k[i] = 2;
        else if(s[i] == 'U') k[i] = 3;
        else k[i] = 4;
    }

    for(int i = 0; i < 9; i++) {
        vis[i][0] = true;
        vis[i][8] = true;
        vis[0][i] = true;
        vis[8][i] = true;
    }

    cout << backtracking(1, 1, 0) << '\n';
}