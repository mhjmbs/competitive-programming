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
        for(int &ai : a) cin >> ai;
        sort(a.begin(), a.end());

        cout << max(a[0]*ll(a[1]), a[n-1]*ll(a[n-2])) << '\n';
    }
}