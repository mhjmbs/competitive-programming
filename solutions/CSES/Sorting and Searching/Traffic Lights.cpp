#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int x, n;
    cin >> x >> n;

    multiset<int> sizes;
    set<pii> intervals;

    intervals.emplace(x, 1);
    sizes.insert(x+1);

    for(int i = 0, tl; i < n; i++) {
        cin >> tl;
        auto it = intervals.lower_bound(make_pair(tl, INT_MIN));
        pii curr = *it;
        if(curr.second <= tl) {
            sizes.erase(sizes.lower_bound(curr.first - curr.second + 1));
            intervals.erase(it);

            if(curr.second <= tl) {
                intervals.emplace(tl, curr.second);
                sizes.insert(tl - curr.second + 1);
            }

            if(tl+1 <= curr.first) {
                intervals.emplace(curr.first, tl+1);
                sizes.insert(curr.first - (tl+1) + 1);
            }
        }

        cout << *sizes.rbegin();
        if(i != n-1) cout << ' ';
        else cout << '\n';
    }
}