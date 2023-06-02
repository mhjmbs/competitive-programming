#include "bits/stdc++.h"
 
#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)
 
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
 
int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        ll ans = 26, x = n-4;

        ans += 2*((x+3)*(x+3+1)/2 - 6) + 3*x;

        cout << ans << '\n';
    }
}