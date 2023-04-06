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
        int n;
        cin >> n;

        ll x, y;
        cin >> x >> y;

        vector<ll> a(n);
        for(ll &ai : a) cin >> ai;
        sort(a.begin(), a.end());

        ll cycle_sum = 0, max_add = 0;
        for(ll ai : a) {
            if(ai <= x + cycle_sum) {
                cycle_sum++;
                max_add = cycle_sum;
            }else cycle_sum--;
        }

        if(max_add >= y-x) {
            cout << y-x << '\n';
            continue;
        }
        if(cycle_sum <= 0) {
            cout << -1 << '\n';
            continue;
        }

        ll curr = x+cycle_sum, games = a.size();
        int next = max_add;

        while(next < n) {
            ll l = 0, r = ll(1e12), ans = -1;

            while(l <= r) {
                ll m = (l+r)/2;

                if(curr + m*cycle_sum + max_add < a[next]) {
                    ans = m;
                    l = m+1;
                }else {
                    r = m-1;
                }
            }

            if(y <= curr + (ans+1)*cycle_sum + max_add) {
                break;
            }else {
                curr = curr + (ans+1)*cycle_sum;
                cycle_sum += 2;
                max_add++;
                next++;
                games += a.size()*(ans+1);
            }
        }

        if(next == n) {
            cout << games + y-curr << '\n';
        }else {
            ll l = 0, r = ll(1e12), ans = -1;

            while(l <= r) {
                ll m = (l+r)/2;

                if(curr + m*cycle_sum + max_add < y) {
                    ans = m;
                    l = m+1;
                }else {
                    r = m-1;
                }
            }

            games += (ans+1)*a.size();
            curr = curr + (ans+1)*cycle_sum;

            cout << games + y-curr << '\n';
        }
    }
}