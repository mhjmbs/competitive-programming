#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;



int main() {
    fastio;

    int n;
    cin >> n;

    set<pii> sRanges, sReversedRanges;
    vector<pii> ranges(n), reversedRanges(n);
    map<pii,int> indexOf;
    vector<int> contains(n, 0), isContained(n, 0);

    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        ranges[i] = {l,r};
        reversedRanges[i] = {r,l};
        sRanges.emplace(l,r);
        sReversedRanges.emplace(r,l);
        indexOf[{l,r}] = i;
    }

    auto func = [](pii a, pii b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    };

    sort(ranges.begin(), ranges.end(), func);
    sort(reversedRanges.begin(), reversedRanges.end(), func);

    for(int i = 0; i < n; i++) {
        auto [l,r] = ranges[i];
        sReversedRanges.erase({r,l});
        if(!sReversedRanges.empty() && sReversedRanges.begin()->first <= r) {
            contains[indexOf[{l,r}]] = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        auto [r,l] = reversedRanges[i];
        sRanges.erase({l,r});
        if(!sRanges.empty() && sRanges.begin()->first <= l) {
            isContained[indexOf[{l,r}]] = 1;
        }
    }

    for(int x : contains) cout << x << ' ';
    cout << '\n';

    for(int x : isContained) cout << x << ' ';
    cout << '\n';
}