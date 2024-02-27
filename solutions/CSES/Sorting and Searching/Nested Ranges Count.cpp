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
 
using ordered_set = tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
 
int main() {
    fastio;
 
    int n;
    cin >> n;
 
    ordered_set sRanges, sReversedRanges;
    vector<tiii> ranges(n);
    vector<int> contains(n, 0), isContained(n, 0);
 
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        ranges[i] = {l,r,i};
        sRanges.insert({l,r});
        sReversedRanges.insert({r,l});
    }
 
    sort(ranges.begin(), ranges.end(), [](tiii a, tiii b) {
        if(get<0>(a) == get<0>(b)) return get<1>(a) > get<1>(b);
        return get<0>(a) < get<0>(b);
    });
 
    for(int i = 0; i < n; i++) {
        auto [l,r,j] = ranges[i];
        sReversedRanges.erase({r,l});
        contains[j] += sReversedRanges.order_of_key({r,INT_MAX});
    }
 
    sort(ranges.begin(), ranges.end(), [](tiii a, tiii b) {
        if(get<1>(a) == get<1>(b)) return get<0>(a) > get<0>(b);
        return get<1>(a) < get<1>(b);
    });
 
    for(int i = 0; i < n; i++) {
        auto[l,r,j] = ranges[i];
        sRanges.erase({l,r});
        isContained[j] += sRanges.order_of_key({l,INT_MAX});
    }
 
    for(int x : contains) cout << x << ' ';
    cout << '\n';
 
    for(int x : isContained) cout << x << ' ';
    cout << '\n';
}