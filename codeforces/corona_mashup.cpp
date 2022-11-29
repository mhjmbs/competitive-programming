#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<ll> m(n);

    for(ll& member : m) cin >> member;

    sort(m.begin(), m.end());
    
    ll ans = -1;

    for(int i = 0; i < n; i++) {
        if(i == n-1 || m[i] != m[i+1]) {
            if((i+1) % 3 == 0) {
                ans = m[i];
            }
        }        
    }

    cout << ans << '\n';
}
