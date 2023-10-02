#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int sumDigits(int x) {
    int ans = 0;
    while(x != 0) {
        ans += x%10;
        x /= 10;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for(int &x : a) cin >> x;

        map<int,int> active;
        for(int i = 0; i < n; i++) active[i] = 0;

        while(q--) {
            int qt;
            cin >> qt;

            if(qt == 1) {
                int l, r;
                cin >> l >> r;
                l--, r--;

                while(l <= r) {
                    auto it = active.lower_bound(l);

                    if(it == active.end()) break;

                    int i = (*it).first;

                    if(r < i) break;

                    a[i] = sumDigits(a[i]);
                    (*it).second++;

                    if((*it).second == 3) active.erase(it);

                    l = i+1;
                }

            }else {
                int x;
                cin >> x;
                x--;

                cout << a[x] << '\n';
            }
        }
    }
}