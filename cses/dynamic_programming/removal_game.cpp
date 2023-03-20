#include "bits/stdc++.h"
 
#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)
 
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
 
ll memo[5000][5000][2];
int x[5000];
 
ll dp(int l, int r, int p) {
    if(memo[l][r][p] != LONG_LONG_MIN) {
        return memo[l][r][p];
    }
 
    if(l == r) {
        if(p == 0) return memo[l][r][p] = x[l];
        else return memo[l][r][p] = -x[l];
    }
 
    if(p == 0) {
        if(dp(l+1, r, 1) + x[l] > dp(l, r-1, 1) + x[r]) {
            return memo[l][r][p] = dp(l+1, r, 1) + x[l];
        }else {
            return memo[l][r][p] = dp(l, r-1, 1) + x[r];
        }
    }else {
        if(dp(l+1, r, 0) - x[l] < dp(l, r-1, 0) - x[r]) {
            return memo[l][r][p] = dp(l+1, r, 0) - x[l];
        }else {
            return memo[l][r][p] = dp(l, r-1, 0)- x[r];
        }
    }
}
 
int main() {
    fastio;
 
    int n;
    cin >> n;
 
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        sum += x[i];
    }
 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < 2; k++) memo[i][j][k] = LONG_LONG_MIN;
        }
    }
 
    cout << (sum + max(dp(0, n-1, 0), dp(0, n-1, 1)))/2 << '\n';
}