#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

int main() {
    fastio;

    int n, a, b;
    cin >> n >> a >> b;

    vector<ll> h(n);
    for(ll &hi : h) cin >> hi;
    sort(h.begin(), h.end());

    vector<ll> p(n+1, 0);
    for(int i = 1; i <= n; i++) {
        p[i] = p[i-1] + h[i-1];
    }

    ll ans = LONG_LONG_MAX;

    for(int i = 1; i <= n; i++) {
        ans = min(ans, a*((i-1)*h[i-1] - p[i-1]) + b*((p[n] - p[i]) - (n-i)*h[i-1]) );
    }

    cout << ans << '\n';
}