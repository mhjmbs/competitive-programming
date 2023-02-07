#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> a(n+1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<ll> prefix(n+1);
    for(int i = 1; i <=n; i++) prefix[i] = prefix[i-1] + a[i];

    set<ll> occur;
    occur.insert(0);
    ll ans = LONG_LONG_MIN;

    for(int i = 1; i <= n; i++) {
        ans = max(ans, prefix[i] - *(occur.begin()));
        occur.insert(prefix[i]);
    }

    cout << ans << '\n';
}