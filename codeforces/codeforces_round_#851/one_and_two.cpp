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

        vector<int> a(n);
        for(int &x : a) cin >> x;

        vector<int> freq2(n, 0), freq2r(n, 0);

        for(int i = 0; i < n; i++) {
            if(i != 0) freq2[i] = freq2[i-1];
            if(a[i] == 2) freq2[i]++;
        }
        for(int i = n-1; 0 <= i; i--) {
            if(i != n-1) freq2r[i] = freq2r[i+1];
            if(a[i] == 2) freq2r[i]++;
        }

        int ans = -1;

        for(int i = 0; i < n-1; i++) {
            if(freq2[i] == freq2r[i+1]) {
                ans = i+1;
                break;
            }
        }

        cout << ans << '\n';
    }
}