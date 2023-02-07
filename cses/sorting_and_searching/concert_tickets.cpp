#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    vector<int> t(m);
    multiset<int> h;
    for(int i = 0, inp; i < n; i++) {
        cin >> inp;
        h.insert(inp);
    }
    for(int &x : t) cin >> x;

    vector<int> bought(m, -1);

    for(int i = 0; i < m; i++) {
        auto it = h.upper_bound(t[i]);
        if(it == h.begin()) continue;
        it--;
        bought[i] = *it;
        h.erase(it);
    }

    for(int i = 0; i < m; i++) {
        cout << bought[i] << '\n';
    }
}