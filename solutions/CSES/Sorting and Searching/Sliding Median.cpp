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

    int n, k;
    cin >> n >> k;

    vector<int> x(n);
    for(int &xi : x) cin >> xi;

    int start = 0, end = 0;

    ordered_multiset values;

    while(end < k) {
        values.insert(x[end]);
        end++;
    }

    while(true) {
        cout << *values.find_by_order((k-1)/2);
        if(end < n) cout << ' ';
        else cout << '\n';

        if(end == n) break;
        
        values.erase(values.upper_bound(x[start]));
        start++;
        values.insert(x[end]);
        end++;
    }
}