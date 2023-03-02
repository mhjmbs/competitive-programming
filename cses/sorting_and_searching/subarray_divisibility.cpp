#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> a(n);
    for(int &ai : a) cin >> ai;

    vector<ll> prefix(n+1, 0);
    for(int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + a[i-1];

    map<ll,ll> occur;
    occur[0] = 1;

    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        int toFind = prefix[i] % n;
        if(toFind < 0) toFind += n;
        auto it = occur.find(toFind);
        if(it != occur.end()) ans += it->second;
        occur[toFind]++;
    }

    cout << ans << '\n';
}