#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        char init;
        string s;
        cin >> n >> init;
        cin >> s;

        for(int i = 0; i < n; i++) {
            s.push_back(s[i]);
        }

        if(init == 'g') {
            cout << 0 << '\n';
            continue;
        }

        int ans = 0, curr = 0;
        bool waiting = false;
        for(char c : s) {
            if(c == init && !waiting) {
                waiting = true;
                curr++;
            }else if(waiting && c == 'g') {
                ans = max(ans, curr);
                curr = 0;
                waiting = false;
            }else if(waiting) {
                curr++;
            }
        }

        cout << ans << '\n';
    }
}