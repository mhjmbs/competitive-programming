#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n;
    cin >> n;

    vector<pii> times(2*n);

    for(int i = 0, a, b; i < 2*n; i+=2) {
        cin >> a >> b;
        times[i] = {a, 0};
        times[i+1] = {b, 1};
    }

    sort(times.begin(), times.end());

    int ans = 0, now = 0;

    for(pii customer : times) {
        int status = customer.second;
        
        if(status == 0) now++;
        else now--;
        ans = max(ans, now);
    }

    cout << ans << '\n';
}