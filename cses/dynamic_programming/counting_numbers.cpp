#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

ll solve(string num) {

    vector<vector<vector<ll>>> dp(num.size()+1, vector<vector<ll>>(10, vector<ll>(2, 0)));

    for(int fd = 0; fd <= 9; fd++) {
        dp[1][fd][0] = 1;
        if(fd <= num[num.size()-1] -'0') dp[1][fd][1] = 1;
    }

    for(int n = 2; n <= num.size(); n++) {
        int max_fd = num[num.size()-n] - '0';
        int max_sd = num[num.size()-n+1] - '0';

        for(int fd = 0; fd <= 9; fd++) {
            if(fd == max_fd) {
                for(int sd = 0; sd <= max_sd; sd++) {
                    if(fd == sd) continue;

                    if(sd == max_sd){
                        dp[n][fd][1] += dp[n-1][sd][1];
                    }else {
                        dp[n][fd][1] += dp[n-1][sd][0];
                    }
                }
            }
            
            for(int sd = 0; sd <= 9; sd++) {
                if(fd == sd) continue;
                dp[n][fd][0] += dp[n-1][sd][0];
            }
        }

        dp[n-1][0][0] += dp[n-2][0][0];
        dp[n-1][0][1] += dp[n-2][0][1];
    }

    dp[num.size()][0][0] += dp[num.size()-1][0][0];
    dp[num.size()][0][1] += dp[num.size()-1][0][1];

    ll ans = 0;
    for(int i = 0; i <= num[0]-'0'; i++) { 
        ans +=  dp[num.size()][i][i == num[0]-'0' ? 1 : 0];
    }

    return ans;
}

int main() {
    fastio;

    string l, r;
    cin >> l >> r;
    l = to_string(stoll(l)-1);
    
    ll ansl = stoll(l) >= 0 ? solve(l) : 0;
    ll ansr = solve(r);

    //cout << "ans de " << l << ": " << ansl << '\n';
    //cout << "ans de " << r << ": " << ansr << '\n';
    cout << ansr - ansl << '\n';
}