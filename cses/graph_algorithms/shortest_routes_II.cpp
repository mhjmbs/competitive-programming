#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> minDist(n+1, vector<ll>(n+1, ll(1e17)));

    for(int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        minDist[a][b] = min(int(minDist[a][b]), c);
        minDist[b][a] = min(int(minDist[b][a]), c);
    }

    for(int i = 1; i <= n; i++) {
        minDist[i][i] = 0;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                minDist[i][j] = min(minDist[i][j], minDist[i][k] + minDist[k][j]);
            }
        }
    }

    for(int i = 0, a, b; i < q; i++) {
        cin >> a >> b;
        if(minDist[a][b] == ll(1e17)) {
            cout << "-1\n";
        }else {
            cout << minDist[a][b] << '\n';
        }
    }
}
