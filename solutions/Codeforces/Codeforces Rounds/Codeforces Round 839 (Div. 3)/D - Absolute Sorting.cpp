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
        int n;
        cin >> n;

        vector<int> a(n);
        for(int &x : a) cin >> x;

        int max_x = INT_MAX, min_x = 0;

        for(int i = 0; i < n-1; i++) {
            if(a[i] < a[i+1]) {
                max_x = min(max_x, a[i] + (a[i+1]-a[i])/2);
            }else if(a[i] > a[i+1]){
                min_x = max(min_x, a[i+1] + (a[i]-a[i+1])/2 + (a[i]-a[i+1])%2);
            }
        }

        if(max_x < min_x) cout << "-1\n";
        else cout << min_x << '\n';
    }
}