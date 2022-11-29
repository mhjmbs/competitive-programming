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
        for(int& ai : a) cin >> ai;

        vector<bool> in(n+1);
        
        int ans;

        for(int i = n-1; 0 <= i; i--) {
            if(!in[a[i]]) {
                ans = i;
                in[a[i]] = true;
            }else {
                break;
            }
        }

        cout << ans << '\n';
    }
}
