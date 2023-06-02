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
        int n, c;
        cin >> n >> c;

        vector<int> a(n+1);
        for(int i = 1; i < n+1; i++) cin >> a[i];

        for(int i = 1; i < n+1; i++) a[i] += i;

        sort(a.begin(), a.end());
        
        int ans = 0;
        for(int i = 1, currc = 0; i < n+1; i++) {
            if(currc + a[i] > c) break;
            currc += a[i];
            ans++;
        }

        cout << ans << '\n';
    }
}