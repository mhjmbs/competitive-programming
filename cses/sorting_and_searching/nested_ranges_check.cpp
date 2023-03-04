#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)
 
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int,int>;
 
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
 
int main() {
    fastio;
 
    int n;
    cin >> n;
 
    vector<pii> original_ranges(n), ranges(n);
    for(pii &curr : ranges) cin >> curr.first >> curr.second;
    original_ranges = ranges;
 
    auto earliest_end = [](pii a, pii b) {
        if(a.second < b.second) return true;
        else if(a.second > b.second) return false;
        else return a.first > b.first;
    };
    sort(ranges.begin(), ranges.end(), earliest_end);
 
    ordered_multiset starts;
    map<pii,int> ans1;
 
    for(pii curr : ranges) {
        ans1[curr] += starts.size() - starts.order_of_key(curr.first);
        starts.insert(curr.first);
    }
 
    ordered_multiset ends;
    map<pii,int> ans2;
    
    auto earliest_start = [](pii a, pii b) {
        if(a.first < b.first) return true;
        else if(a.first > b.first) return false;
        else return a.second > b.second;
    };
    sort(ranges.begin(), ranges.end(), earliest_start);
 
    for(pii curr : ranges) {
        ans2[curr] += ends.size() - ends.order_of_key(curr.second);
        ends.insert(curr.second);
    }
 
    for(int i = 0; i < n; i++) {
        cout << bool(ans1[original_ranges[i]]);
        if(i != n-1) cout << ' ';
        else cout << '\n';
    }
    for(int i = 0; i < n; i++) {
        cout << bool(ans2[original_ranges[i]]);
        if(i != n-1) cout << ' ';
        else cout << '\n';
    }
}