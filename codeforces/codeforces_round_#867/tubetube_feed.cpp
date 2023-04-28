#include "bits/stdc++.h"
 
#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)
 
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
 
int main() {
    fastio;

    int q;
    cin >> q;

    while(q--) {
        int n, t;
        cin >> n >> t;

        vector<int> a(n+1);
        for(int i = 1; i <= n; i++) cin >> a[i];

        vector<int> b(n+1);
        for(int i = 1; i <= n; i++) cin >> b[i];

        int curr_time = 0;
        pair<int,int> best = {-1,-1};

        for(int i = 1; i <= n; i++, curr_time++) {
            if(curr_time + a[i] <= t && b[i] > best.first) {
                best = {b[i], i};
            }
        }

        cout << best.second << '\n';
    }
}