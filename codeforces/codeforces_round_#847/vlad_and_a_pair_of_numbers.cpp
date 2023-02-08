#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using ull = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int x;
        cin >> x;

        if(x % 2 != 0 || (x & (x/2))) {
            cout << -1 << '\n';
            continue;
        }

        int a = x/2+x, b = x/2;
        cout << a << ' ' << b << '\n';
    }
}