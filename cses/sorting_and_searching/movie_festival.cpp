#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n;
    cin >> n;

    vector<pii> times(n);

    for(auto &x : times) cin >> x.first >> x.second;

    auto comp = [&](pii a, pii b) {
        return a.second < b.second;
    };

    sort(times.begin(), times.end(), comp);

    int ans = 0;
    int now = 0;

    for(pii time : times) {
        if(now <= time.first) {
            now = time.second;
            ans++;
        }
    }

    cout << ans << '\n';
}