#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> p(n);
    for(int &x : p) cin >> x;
    sort(p.begin(), p.end());

    int target = p[p.size()/2];

    ll ans = 0;
    for(int x : p) ans += abs(x - target);

    cout << ans << '\n';
}