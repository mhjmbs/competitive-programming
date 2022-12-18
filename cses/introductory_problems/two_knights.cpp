#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    for(ll k = 1; k <= n; k++) {
        ll ans = (k*k * (k*k-1))/2;
        ans -= 4*max(k-2,0ll)*max(k-1,0ll);
        cout << ans << '\n';
    }
}