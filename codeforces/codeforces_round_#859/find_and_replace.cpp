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

        set<char> pair, odd;
        bool yes = true;

        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) pair.insert(s[i]);
            else odd.insert(s[i]);

            if(i % 2 == 0 && odd.find(s[i]) != odd.end()) {
                yes = false;
                break;
            }
            if(i % 2 == 1 && pair.find(s[i]) != pair.end()) {
                yes = false;
                break;
            }
        }

        if(yes) cout << "YES\n";
        else cout << "NO\n";
    }
}