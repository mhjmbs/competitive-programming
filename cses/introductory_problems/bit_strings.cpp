#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    int m = int(1e9) + 7;

    int ans = 1;

    for(int i = 0; i < n; i++) {
        ans *= 2;
        ans %= m;
    }
    cout << ans << '\n';
}