#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for(int &ai : a) cin >> ai;
    
    vector<pii> s(n);
    for(int i = 0; i < n; i++) {
        s[i] = {a[i], i+1}; 
    }

    sort(s.begin(), s.end());

    int ans[3] = {-1,-1,-1};

    for(int i = 0; i < n-2; i++) {
        for(int j = i+1; j < n-1; j++) {
            auto it = lower_bound(s.begin()+j+1, s.end(), make_pair(x-(s[i].first+s[j].first), INT_MIN));
            if(it != s.end() && it->first == x-(s[i].first+s[j].first)) {
                ans[0] = s[i].second;
                ans[1] = s[j].second;
                ans[2] = it->second;
            } 
        }
    }

    if(ans[0] == -1) cout << "IMPOSSIBLE\n";
    else cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n'; 
}