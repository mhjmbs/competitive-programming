#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int test;
    cin >> test;

    while(test--) {
        int n, k;
        cin >> n >> k;

        string s, t;
        cin >> s >> t;

        vector<int> freqs(26, 0), freqt(26, 0);

        for(int i = 0; i < n; i++) {
            freqs[s[i]-'a']++;
            freqt[t[i]-'a']++;
        }

        if(freqs != freqt) {
            cout << "NO\n";
            continue;
        }

        if(s == t) {
            cout << "YES\n";
            continue;
        }

        bool yes = true;

        for(int i = 0; i < n; i++) {
            if(k > n-1 - i && k > i && s[i] != t[i]) {
                yes = false;
                break;
            }
        }

        if(yes) cout << "YES\n";
        else cout << "NO\n";
    }
}