#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n;
    cin >> n;

    set<int> distinct;

    for(int i = 0, inp; i < n; i++) {
        cin >> inp;
        distinct.insert(inp);
    }

    cout << distinct.size() << '\n';
}