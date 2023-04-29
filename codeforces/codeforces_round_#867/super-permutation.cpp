#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        if(n % 2 == 1 && n != 1) {
            cout << -1 << '\n';
            continue;
        }

        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) cout << n-i;
            else cout << i;
            if(i != n-1) cout << ' ';
            else cout << '\n';
        }
    }
}