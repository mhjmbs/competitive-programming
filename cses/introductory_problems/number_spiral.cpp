#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--) {
        ll y, x, ans;
        cin >> y >> x;

        if(y >= x) {
            ans = 1 + (y-1)*y;
            if(y % 2 == 0) ans += y-x;
            else ans -= y-x;
        }else {
            ans = 1 + (x-1)*x;
            if(x % 2 == 0) ans -= x-y;
            else ans += x-y;
        }

        cout << ans << '\n'; 
    }    
}