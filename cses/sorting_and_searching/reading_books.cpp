#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> t(n);
    for(int &ti : t) cin >> ti;
    sort(t.begin(), t.end());

    if(n == 1) {
        cout << t[0]*2 << '\n';
        exit(0);
    }

    ll sum = 0;
    for(int i = 0; i < n; i++) sum += t[i];

    ll diff = max(t[n-1] - (sum-t[n-1]), 0ll);

    cout << sum + diff << '\n';
}