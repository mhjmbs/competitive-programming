#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> coins(n);
    for(int &c : coins) cin >> c;

    set<int> sums;

    for(int &c : coins) {
        set<int> toAdd;
        for(int sum : sums) toAdd.insert(sum+c);
        sums.merge(toAdd);
        sums.insert(c);
    }

    cout << sums.size() << '\n';

    auto last = sums.end();
    last--;

    for(auto it = sums.begin(); it != sums.end(); it++) {
        cout << *it;
        if(it != last) cout << ' ';
        else cout << '\n';
    }
}