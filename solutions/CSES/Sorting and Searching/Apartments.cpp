#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);

    for(int &x : a) cin >> x;

    vector<int> b(m);

    for(int &x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;

    for(int i = 0, j = 0; i < m; i++) {
        while(j < n) {
            if(a[j] - k <= b[i] && b[i] <= a[j]+k) {
                ans++;
                j++;
                break;
            }else if(b[i] < a[j]+k) break;
            j++;
        }
    }

    cout << ans << '\n';
}