#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

vector<vector<int>> S;
int goal, ans = 0;
int n, m;

void backtracking(int curr, int taken) {
    if(curr == m) {
        if(taken == goal) {
            ans++;
        }
        return;
    }

    int taking = taken;

    for(int i = 0; i < S[curr].size(); i++) {
        taking |= 1 << (S[curr][i]-1);
    }

    backtracking(curr+1, taking);
    backtracking(curr+1, taken);
}

int main() {
    fastio;

    cin >> n >> m;

    S.resize(m);

    for(int i = 0, ci; i < m; i++) {
        cin >> ci;
        S[i].resize(ci);
        for(int j = 0; j < ci; j++) {
            cin >> S[i][j];
        }
    }

    goal = 1;
    for(int i = 0; i < n-1; i++) {
        goal *= 2;
        goal++;
    }

    backtracking(0, 0);

    cout << ans << '\n';
}