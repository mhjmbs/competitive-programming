#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<char> correspL(51, '#'), f(n);

        for(int i = 0; i < n; i++) cin >> a[i];

        string s;
        cin >> s;

        for(int i = 0; i < n; i++) {
            int currNum = a[i];
            if(correspL[currNum] == '#') {
                correspL[currNum] = s[i];
            }

            f[i] = correspL[currNum];
        }

        bool possible = true;
        for(int i = 0; i < n; i++) {
            if(f[i] != s[i]) {
                possible = false;
                break;
            }
        }

        if(possible) cout << "YES\n";
        else cout << "NO\n";
    }
}