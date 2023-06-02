#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

ll dp[14][10][2];

ll check(ll n) {

    string s = to_string(n); 

    for(int d = 0; d <= 9; d++) {
        if(d == 4) continue;
        dp[1][d][0] = 1;
        dp[1][d][1] = 1;
    }

    for(int n = 2; n <= s.size(); n++) {
        for(int d = 0; d <= 9; d++) {
            if(d == 4) continue;

            for(int d2 = 0; d2 <= 9; d2++) {
                dp[n][d][0] += dp[n-1][d2][0];
            }

            int tight_d2 = s[s.size()-n] - '0'== d ? s[s.size()-n+1] - '0' : 9;

            for(int d2 = 0; d2 <= tight_d2; d2++) {
                if(d2 == tight_d2) dp[n][d][1] += dp[n-1][d2][1];
                else dp[n][d][1] += dp[n-1][d2][0];
            }
        }
    }

    ll ans = 0;
    for(int d = 0; d <= s[0]-'0'; d++) {
        if(d == s[0]-'0') ans += dp[s.size()][d][1];
        else ans += dp[s.size()][d][0];
    }
    ans--;

    return ans;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;

        ll l = 0, r = ll(1e13), ans = -1;

        while(l <= r) {
            ll m = (l+r)/2;

            for(int i = 0; i < 14; i++) {
                for(int j = 0; j < 10; j++) {
                    for(int k = 0; k < 2; k++) {
                        dp[i][j][k] = 0;
                    }
                }
            }
            ll index = check(m);

            if(n <= index) {
                ans = m;
                r = m-1;
            }else {
                l = m+1;
            }
        }

        cout << ans << '\n';
    }
}