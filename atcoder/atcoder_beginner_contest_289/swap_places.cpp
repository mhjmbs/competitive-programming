#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using tiii = tuple<int,int,int>;

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<int> c(n);
        for(int &x : c) cin >> x;

        vector<vector<int>> adjacencies(n);
        for(int i = 0, u, v; i < m; i++) {
            cin >> u >> v;
            u--;v--;
            adjacencies[u].push_back(v);
            adjacencies[v].push_back(u);
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));
        dp[0][n-1] = 0;

        queue<tiii> q;
        q.emplace(0, n-1, 0);

        while(!q.empty()) {
            int a, b, d;
            tie(a, b, d) = q.front();
            q.pop();

            for(int adjA : adjacencies[a]) {
                for(int adjB : adjacencies[b]) {
                    if(c[adjA] != c[adjB] && dp[adjA][adjB] == -1) {
                        dp[adjA][adjB] = d+1;
                        q.emplace(adjA, adjB, d+1);
                    }
                }
            }
        }

        cout << dp[n-1][0] << '\n';
    }
}