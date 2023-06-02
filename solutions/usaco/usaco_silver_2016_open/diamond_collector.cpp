#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

int main() {
    fastio;

    ifstream cin("diamond.in");
    ofstream cout("diamond.out");

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int &x : a) cin >> x;
    sort(a.begin(), a.end());

    vector<int> left(n,0), right(n,0);

    for(ll e = 0, s = 0, cs = 0; e < n; e++) {
        cs += a[e];
        while(a[s] < a[e]-k) {
            cs -= a[s];
            s++;
        }
        
        left[e] = e == 0 ? e-s+1 : max(int(e-s+1), left[e-1]);
    }

    for(ll e = n-1, s = n-1, cs = 0; e >= 0; e--) {
        cs += a[e];
        while(a[e]+k < a[s]) {
            cs -= a[s];
            s--;
        }
        
        right[e] = e == n-1 ? s-e+1 : max(int(s-e+1), right[e+1]);
    }

    int ans = INT_MIN;

    for(int i = 1; i < n; i++) {
        ans = max(ans, left[i-1] + right[i]);
    }

    cout << ans << '\n';
}