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
        ll a, b;
        cin >> a >> b;

        bool poss1 = true, poss2 = true;

        if((a-2*b) % -3 != 0 || (a-2*b) / -3 < 0 || b - 2*(a-2*b) / -3 < 0) poss1 = false;
        if((b-2*a) % -3 != 0 || (b-2*a) / -3 < 0 || a - 2*(b-2*a) / -3 < 0) poss2 = false;

        if(poss1 || poss2) cout << "YES\n";
        else cout << "NO\n";
    }
}