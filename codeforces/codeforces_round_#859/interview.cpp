#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int query(int l, int m) {
    cout << "? " << m-l+1 << ' ';

    while(l <= m) {
        cout << l;
        if(l != m) cout << ' ';
        else cout << endl;
        l++;
    }

    int w;
    cin >> w;
    return w;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> p(n+1), prefix(n+1, 0);
        for(int i = 1; i <= n; i++) {
            cin >> p[i];
            prefix[i] = prefix[i-1] + p[i];
        }

        int l = 1, r = n, ans = -1;

        while(l <= r) {
            int m = (l+r)/2;

            int w = query(l, m);

            if(w == prefix[m] - prefix[l-1]) {
                l = m+1;
            }else {
                ans = m;
                r = m-1;
            }
        }

        cout << "! " << ans << endl;
    }
}