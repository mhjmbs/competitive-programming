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

        string s;
        cin >> s;

        int ans = 1;

        for(int i = 2; i < n; i++) {
            if(s[i] != s[i-2]) ans++;
        }

        cout << ans << '\n';
    }
}