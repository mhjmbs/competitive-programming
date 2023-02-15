#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n, m, x;
    vector<int> a;
    vector<bool> b(100001, false);

    cin >> n;
    a.resize(n);
    for(int &yay : a) cin >> yay;
    cin >> m;
    for(int i = 0, inp; i < m; i++) {
        cin >> inp;
        b[inp] = true;
    }
    cin >> x;

    vector<bool> dp(100001);

    dp[0] = true;

    for(int pos = 1; pos <= x; pos++) {
        if(b[pos]) continue;
        for(int jump : a) {
            if(pos - jump < 0) continue;
            dp[pos] = dp[pos] || dp[pos-jump];
        }
    }

    if(dp[x]) cout << "Yes\n";
    else cout << "No\n";
}