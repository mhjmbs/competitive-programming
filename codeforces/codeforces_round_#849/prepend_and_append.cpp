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

        int ans = n;

        int l = 0, r = n-1;

        while(l < r) {
            if(s[l] == '0' && s[r] == '1' || s[l] == '1' && s[r] == '0') {
                ans -= 2;
                l++;
                r--;
            }else {
                break;
            }
        }
        cout << ans << '\n';
    }
}