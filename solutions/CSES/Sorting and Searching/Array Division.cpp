#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int n, k;

bool process(vector<int> x, ll m) {
    ll currSum = 0, divisions = 1;

    for(int i = 0; i < n; i++) {
        if(currSum + x[i] > m) {
            if(x[i] > m) {
                return false;
            }else {
                currSum = x[i];
                divisions++;
            }
        }else {
            currSum += x[i];
        }
    }

    if(divisions > k) return false;
    return true;
}

int main() {
    fastio;

    cin >> n >> k;

    vector<int> x(n);
    for(int &xi : x) cin >> xi;

    ll l = 0, r = ll(1e15), ans = -1;

    while(l <= r) {
        ll m = (l+r)/2;

        bool possible = process(x, m);

        if(possible) {
            ans = m;
            r = m-1;
        }else {
            l = m+1;
        }
    }

    cout << ans << '\n';
}