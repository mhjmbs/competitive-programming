#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n;
    cin >> n;

    multiset<int> s;

    for(int i = 0, b; i < n; i++) {
        cin >> b;
        auto it = s.upper_bound(b);
        if(it != s.end()) s.erase(it);
        s.insert(b);
    }

    cout << s.size() << '\n';
}