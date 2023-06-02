#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    vector<int> b(n), s(m);
    for(int &x : b) cin >> x;
    for(int &x : s) cin >> x;

    int ans = 0;
    int b_i = 0, s_i = 0;

    for(; b_i < n; b_i++) {
        while(s[s_i] < b[b_i]) {
            ans += s[s_i];
            s_i++;
        }
        ans += s[s_i] - b[b_i];
        s_i++;
    }

    while(s_i < m) {
        ans += s[s_i];
        s_i++;
    }

    cout << ans << '\n';
}