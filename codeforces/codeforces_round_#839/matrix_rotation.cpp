#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

bool beaut(vector<vector<int>> &m) {
    if(m[0][0] < m[0][1]
    && m[1][0] < m[1][1]
    && m[0][0] < m[1][0]
    && m[0][1] < m[1][1])
        return true;
    return false;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        vector<vector<int>> m(2, vector<int>(2));
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                cin >> m[i][j];
            }
        }

        bool yes = false;

        for(int i = 0; i < 4; i++) {
            vector<vector<int>> newm = {{m[1][0],m[0][0]}, {m[1][1],m[0][1]}};
            yes = yes || beaut(m);
            m = newm;
        }

        if(yes) cout << "YES\n";
        else cout << "NO\n";
    }
}