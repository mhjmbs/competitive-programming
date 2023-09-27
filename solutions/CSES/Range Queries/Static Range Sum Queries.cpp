#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n, q;
    cin >> n >> q;

    vector<ll> x(n+1, 0);
    for(int i = 1; i <=n; i++) cin >> x[i];

    vector<ll> p(n+1, 0);
    for(int i = 0; i <= n; i++) {
        p[i] = p[i-1] + x[i];
    }

    for(int i = 0, l, r; i < q; i++) {
        cin >> l >> r;
        cout << p[r]-p[l-1] << '\n';
    }
}