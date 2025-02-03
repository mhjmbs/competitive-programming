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

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    
    for(string& row : grid) {
        cin >> row;
    }

    vector<vector<map<char,int>>> freq(2);
    freq[0].resize(n);
    freq[1].resize(m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c = grid[i][j];
            freq[0][i][c]++;
            freq[1][j][c]++;
        }
    }

    queue<pii> q;

    for(int i = 0; i < n; i++) {
        if(freq[0][i].size() == 1) q.emplace(0,i);
    }
    for(int j = 0; j < m; j++) {
        if(freq[1][j].size() == 1) q.emplace(1,j);
    }

    vector<tuple<char,int,char>> ans;

    while(!q.empty()) {
        auto [axis, index] = q.front();
        q.pop();

        if(freq[axis][index].empty()) continue;

        char c = freq[axis][index].begin()->first;
        freq[axis][index].clear();
        
        ans.emplace_back(
            (axis == 0) ? 'R' : 'K',
            index+1,
            c
        );

        int end = (axis == 0) ? m : n;
        
        for(int i = 0; i < end; i++) {
            char& curr_c = (axis == 0) ? grid[index][i] : grid[i][index];
            if(curr_c != c) continue;
            curr_c = '-';
            freq[!axis][i][c]--;
            if(freq[!axis][i][c] == 0) freq[!axis][i].erase(c);
            if(freq[!axis][i].size() == 1) q.emplace(!axis, i);
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << '\n';

    for(auto [axis, i, c] : ans) {
        cout << axis << ' ' << i << ' ' << c << '\n';
    }
}