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

    ll currSum = 0;

    int ans = 0;

    for(int start = 0, end = 0; end < n; end++) {
        currSum += a[end];
        while(currSum > x && start <= end) {
            currSum -= a[start];
            start++;
        }

        if(currSum == x) ans++;
    }

    cout << ans << '\n';
}