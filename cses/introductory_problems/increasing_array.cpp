#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);

    int n, last = 0;
    cin >> n;
    
    ll ans = 0;

    for(int i = 0, inp; i < n; i++) {
        cin >> inp;
        ans += max(0, last-inp);
        last = max(inp, last);
    }

    cout << ans << '\n';
}