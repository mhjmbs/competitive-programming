#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n, q;
        cin >> n >> q;

        vector<ll> prefix(n+1, 0);
        for(int i = 1, inp; i <= n; i++) {
            cin >> inp;
            prefix[i] = prefix[i-1] + inp;
        }

        for(int i = 0; i < q; i++) {
            ll l, r, k;
            cin >> l >> r >> k;

            if((prefix[n] - (prefix[r] - prefix[l-1]) + k*(r-l+1)) % 2 == 1) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}