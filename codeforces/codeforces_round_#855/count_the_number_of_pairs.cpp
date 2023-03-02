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
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<int> upper(26, 0), lower(26, 0);

        for(char c : s) {
            if(c >= 'a') lower[c-'a']++;
            else upper[c-'A']++;
        }

        int ans = 0;

        for(int i = 0; i < 26; i++) {
            int big = max(upper[i], lower[i]);
            int small = min(upper[i], lower[i]);

            int maxop = (big-small)/2;

            if(k >= maxop) {
                small += maxop;
                k -= maxop;
            }else {
                small += k;
                k = 0;
            }

            ans += small;
        }

        cout << ans << '\n';
    }
}