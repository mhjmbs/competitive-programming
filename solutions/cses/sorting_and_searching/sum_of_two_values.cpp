#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n, x;
    cin >> n >> x;

    vector<ll> a(n);
    for(ll &x : a) cin >> x;
    vector<ll> original = a;
    sort(a.begin(), a.end());

    pii ans = {-1,-1};

    for(int i = 0; i < n-1; i++) {
        ll target = x - a[i]; 
        auto it = lower_bound(a.begin()+i+1, a.end(), target);
        if(it != a.end() && *it == target) {
            ans = {a[i], *it};
            break;
        }
    }

    if(ans != make_pair(-1,-1)) {
        for(int i = 0; i < n; i++) {
            if(original[i] == ans.first) {
                ans.first = i+1;
                break;
            }
        }

        for(int i = n-1; 0 <= i; i--) {
            if(original[i] == ans.second) {
                ans.second = i+1;
                break;
            }
        }

        cout << ans.first << ' ' << ans.second << '\n';
    }else {
        cout << "IMPOSSIBLE\n";
    }
}