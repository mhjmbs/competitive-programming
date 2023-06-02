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
        int n;
        cin >> n;

        vector<int> c(n);
        for(int &ci : c) cin >> ci;
        sort(c.begin(), c.end());

        if(c[0] != 1) {
            cout << "NO\n";
            continue;
        }

        ll maxSum = 1;
        bool yes = true;

        for(int i = 1; i < n; i++) {
            if(maxSum < c[i]) {
                yes = false;
                break;
            }
            maxSum += c[i];
        }

        if(yes) cout << "YES\n";
        else cout << "NO\n";
    }
}