#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n-1), ans(n);
        for(int &x : a) cin >> x;

        ans[0] = a[0];
        a.push_back(INT_MAX);

        for(int i = 1; i < n; i++) {
            ans[i] = min(a[i], a[i-1]);
        }

        for(int i = 0; i < n; i++) {
            cout << ans[i];
            if(i != n-1) cout << ' ';
            else cout << '\n';
        }
    }
}