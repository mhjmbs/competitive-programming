#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

int succ[200001][32];

int succ_f(int x, int k) {
    if (succ[x][k] != -1) return succ[x][k];
    return succ[x][k] = succ_f(succ_f(x, k-1), k-1);
}

int main() {
    fastio;

    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 32; j++) succ[i][j] = -1;
    }
    for(int i = 1; i <= n; i++) cin >> succ[i][0];

    for(int i = 0, x, k; i < q; i++) {
        cin >> x >> k;
        
        for(int j = 0; j < 32; j++) {
            if(k & (1<<j)) {
                x = succ_f(x, j);
            }
        }
        cout << x << '\n';
    }
}