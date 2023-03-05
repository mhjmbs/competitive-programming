#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pip = pair<int, pair<int,int>>;

int main() {
    fastio;

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for(int & ai : a) cin >> ai;

    multiset<pip> sums;

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            sums.emplace(a[i]+a[j], make_pair(i,j));
        }
    }

    for(auto curr : sums) {
        auto it = sums.lower_bound(make_pair(x-curr.first, make_pair(-1,-1)));
        if(it != sums.end()) {
            while(true) {
                if(it->first == x-curr.first
                && curr.second.first != it->second.first && curr.second.first != it->second.second
                && curr.second.second != it->second.first && curr.second.second != it->second.second) {
                    cout << curr.second.first+1 << ' ' << curr.second.second+1 << ' ' << it->second.first+1 << ' ' << it->second.second+1 << '\n';
                    return 0;
                }else {
                    it = sums.upper_bound(*it);
                    if(it == sums.end() || it->first != x-curr.first) break;
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}