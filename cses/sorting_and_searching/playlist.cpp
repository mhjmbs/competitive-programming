#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> k(n);
    for(int &ki : k) cin >> ki;

    set<int> s;
    int ans = 0;
    for(int start = 0, end = 0; end < n; end++) {
        if(s.find(k[end]) != s.end()) {
            while(k[start] != k[end]) {
                s.erase(k[start]);
                start++;
            }
            s.erase(k[start]);
            start++;
        }

        s.insert(k[end]);
        ans = max(ans, int(s.size()));
    }

    cout << ans << '\n';
}