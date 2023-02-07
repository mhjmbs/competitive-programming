#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        set<char> freqf, freqr;
        vector<int> fa(n), fb(n);

        for(int i = 0; i < n; i++) {
            freqf.insert(s[i]);
            fa[i] = freqf.size();
        }

        for(int i = n-1; i >= 0; i--) {
            freqr.insert(s[i]);
            fb[i] = freqr.size();
        }

        int ans = 0;

        for(int i = 0; i < n-1; i++) {
            ans = max(ans, fa[i] + fb[i+1]);
        }

        cout << ans << '\n';
    }
}