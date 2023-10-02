#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int &x : a) cin >> x;

        int pos = 0, neg = 0;
        bool zero = false;

        for(int x : a) {
            if(x > 0) pos++;
            else if(x == 0) zero = true;
            else neg++;
        }

        if(zero) {
            ll ans = 0;
            for(int x : a) ans += abs(x);
            cout << ans << '\n';
            continue;
        }

        pos += (neg/2) * 2;

        priority_queue<int> prioq;

        for(int x : a) prioq.push(abs(x));

        ll ans = 0;

        for(int i = 0; i < pos; i++) {
            ans += prioq.top();
            prioq.pop();
        }

        while(!prioq.empty()) {
            ans -= prioq.top();
            prioq.pop();
        }

        cout << ans << '\n';
    }
}