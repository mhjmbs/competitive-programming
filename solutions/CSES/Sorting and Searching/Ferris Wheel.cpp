#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n, x;
    cin >> n >> x;

    int gond = 0;

    vector<int> p(n);
    for(int &x : p) cin >> x;
    sort(p.begin(), p.end());

    vector<bool> used(n, false);

    int l = 0, r = n-1;

    while(l < r) {
        if(p[l] + p[r] <= x) {
            used[l] = used[r] = true;
            gond++; l++; r--;
        }else {
            r--;
        }
    }

    for(int i = 0; i < n; i++) {
        if(!used[i]) gond++;
    }

    cout << gond << '\n';
}