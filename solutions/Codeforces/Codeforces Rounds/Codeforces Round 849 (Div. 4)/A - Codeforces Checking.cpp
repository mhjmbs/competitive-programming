#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    string s = "codeforces";

    int t;
    cin >> t;

    while(t--) {
        char c;
        cin >> c;

        bool yes = false;

        for(char x : s) {
            if(x == c) yes = true;
        }

        if(yes) cout << "YES\n";
        else cout << "NO\n";
    }
}