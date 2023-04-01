#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

char sim(int &orig, int &dest, bool rain) {
    if(rain || dest == 0) {
        orig--;dest++;
        return 'Y';
    }
    return 'N';
}

int main() {
    fastio;

    int n, h, w;
    cin >> n >> h >> w;

    for(int i = 0; i < n; i++) {
        char t1, t2;
        cin >> t1 >> t2;
        cout << sim(h, w, t1 == 'Y' ? true : false) << ' ' << sim(w, h, t2 == 'Y' ? true : false) << '\n';
    }
}