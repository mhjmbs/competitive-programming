#include "bits/stdc++.h"

using namespace std;
using pii = pair<int,int>;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    for(int i = 0, inp; i < n; i++) {
        cin >> inp;
        if(i >= k) cout << inp << ' ';
    }

    k = min(k, n);
    for(int i = 0; i < k; i++) {
        cout << 0;
        if(i+1 == k) cout << '\n';
        else cout << ' ';
    }
}