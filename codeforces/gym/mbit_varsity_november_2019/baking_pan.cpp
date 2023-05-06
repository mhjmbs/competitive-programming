#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

int main() {
    fastio;

    int n;
    cin >> n;

    int max_x = INT_MIN, min_x = INT_MAX, max_y = INT_MIN, min_y = INT_MAX;

    for(int i = 0, x, y, r; i < n; i++) {
        cin >> x >> y >> r;
        max_x = max(max_x, x + r);
        min_x = min(min_x, x - r);
        max_y = max(max_y, y + r);
        min_y = min(min_y, y - r);
    }

    cout << ll(max_x - min_x) * (max_y - min_y) << '\n';
}