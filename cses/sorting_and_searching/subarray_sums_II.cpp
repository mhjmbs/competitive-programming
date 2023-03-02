#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for(int &ai : a) cin >> ai;

    vector<ll> prefix(n+1, 0);
    for(int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + a[i-1];

    map<ll,ll> s;
    s.emplace(0,1);
    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        auto it = s.find(-x+prefix[i]);
        if(it != s.end()) ans += it->second;
        s[prefix[i]]++;
    }

    cout << ans << '\n';
}