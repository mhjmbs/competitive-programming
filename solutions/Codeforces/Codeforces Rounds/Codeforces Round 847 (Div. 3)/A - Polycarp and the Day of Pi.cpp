#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    string pi = "3141592653589793238462643383279";

    int t;
    cin >> t;

    while(t--) {
        string poly;
        cin >> poly;

        int ans = 0;

        for(int i = 0; i < poly.size(); i++) {
            if(pi[i] == poly[i]) ans++;
            else break;
        }

        cout << ans << '\n';
    }
}