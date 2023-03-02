#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int &x : a) cin >> x;

        ll army = 0;

        multiset<int> bonus;

        for(int i = 0; i < n; i++) {
            if(a[i] != 0) {
                bonus.insert(a[i]);
            }else {
                auto it = bonus.end();
                if(bonus.size() != 0) {
                    it--;
                    army += *it;
                    bonus.erase(it);
                }
            }
        }

        cout << army << '\n';
    }
}