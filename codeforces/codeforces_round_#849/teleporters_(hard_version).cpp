#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n, c;
        cin >> n >> c;

        vector<pii> a(n+1);
        for(int i = 1, inp; i <= n; i++) {
            cin >> inp;
            a[i] = {min(inp+i, inp+(n-i)+1), inp+i};
        }

        sort(a.begin(), a.end());

        vector<ll> prefix(n+1, 0);

        for(int i = 1; i <= n; i++) {
            prefix[i] = prefix[i-1] + a[i].first;
        }

        ll ans = 0;

        for(int i = 1; i <= n; i++) {
            ll l = 0, r = n, m, curr_ans = 0, price, taken;

            while(l <= r) {
                m = (l+r)/2;

                price = prefix[m];
                if(m < i) {
                    taken = m+1;
                    price += a[i].second;
                }else {
                    taken = m;
                    price += a[i].second - a[i].first;
                }

                if(price <= c) {
                    curr_ans = taken;
                    l = m+1;
                }else {
                    r = m-1;
                }
            }
            ans = max(ans, curr_ans);
        }

        cout << ans << '\n';
    }
}