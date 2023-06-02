#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n, a, b;
    cin >> n >> a >> b;

    vector<ll> prefix(n+1, 0);
    for(int i = 1, inp; i <= n; i++) {
        cin >> inp;
        prefix[i] = prefix[i-1] + inp;
    }

    ll start = 0, end = b, ans = LONG_LONG_MIN;
    map<ll,ll> occur;
    occur[0]++;

    int next_prefix = 1;

    for(int start = 0, end = a; end <= n;) {
        ans = max(ans, prefix[end] - (*occur.begin()).first);

        if(end == n) break;

        end++;

        if(end-start > b) {
            occur[prefix[start]]--;
            if(occur[prefix[start]] == 0) occur.erase(prefix[start]);
            start++;
        }

        occur[prefix[next_prefix]]++;
        next_prefix++;
    }

    cout << ans << '\n';
}