#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n, x1, y1, x2, y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;

        if(x1 > n/2) x1 -= n/2;
        else x1 = n/2 - x1 + 1;
        if(y1 > n/2) y1 -= n/2;
        else y1 = n/2 - y1 + 1;
        if(y2 > n/2) y2 -= n/2;
        else y2 = n/2 - y2+ 1;
        if(x2 > n/2) x2 -= n/2;
        else x2 = n/2- x2 + 1;

        int c1 = max(x1, y1);
        int c2 = max(x2,y2);

        cout << abs(c1-c2) << '\n';
    }
}