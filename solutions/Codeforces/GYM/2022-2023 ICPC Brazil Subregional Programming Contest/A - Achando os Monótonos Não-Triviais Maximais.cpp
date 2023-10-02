#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    string s;
    cin >> s;
    
    int ans = 0;

    for(int i = 0, aCounter = 0; i < n; i++) {
        if(s[i] == 'a') {
            aCounter++;
        }else {
            if(aCounter > 1) {
                ans += aCounter;
            }
            aCounter = 0;
        }

        if(i+1 == n && aCounter > 1) {
            ans += aCounter;
        }
    }

    cout << ans << '\n';
}
