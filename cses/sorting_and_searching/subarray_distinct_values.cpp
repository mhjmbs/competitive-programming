#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    vector<int> x(n);
    for(int &xi : x) cin >> xi;

    map<int,int> occur;
    ll ans = 0;

    for(int start = 0, end = 0; end < n; end++) {
        occur[x[end]]++;

        while(occur.size() > k) {
            occur[x[start]]--;
            if(occur[x[start]] == 0) occur.erase(x[start]);
            start++;
        }

        ans += end-start+1;
    }

    cout << ans << '\n';
}