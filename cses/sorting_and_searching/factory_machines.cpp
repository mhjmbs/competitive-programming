#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main() {
    fastio;

    ll n, t;
    cin >> n >> t;

    vector<ll> k(n);
    for(ll &ki : k) cin >> ki;

    auto check = [&k](ll curr_time) {
        ll ans = 0;
        for(ll &ki : k) {
            ans += curr_time/ki;
            if(ans < 0) return LONG_LONG_MAX;
        }
        return ans;
    };

    ll l = 0, r = 1e18, ans = -1;

    while(l <= r) {
        ll m = l + (r-l)/2;

        ll curr_ans = check(m);

        if(t <= curr_ans) {
            ans = m;
            r = m-1;
        }else {
            l = m+1;
        }
    }

    cout << ans << '\n';
}