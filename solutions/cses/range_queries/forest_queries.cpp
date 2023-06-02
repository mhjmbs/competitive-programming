#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n, q;
    cin >> n >> q;

    vector<string> grid(n);
    for(string &s : grid) cin >> s;

    vector<vector<int>> prefix(n+1, vector<int>(n+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(grid[i-1][j-1] == '*') prefix[i][j]++;
            prefix[i][j] += prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }

    for(int i = 0, y1, x1, y2, x2; i < q; i++) {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << prefix[y2][x2] - prefix[y1-1][x2] - prefix[y2][x1-1] + prefix[y1-1][x1-1] << '\n';
    }

}