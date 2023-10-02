#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;



int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int &ai : a) cin >> ai;

        int min_diff = INT_MAX;
        bool is_sorted = true;

        for(int i = 0; i < n-1; i++) {
            if(a[i] > a[i+1]) {
                is_sorted = false;
            }else {
                min_diff = min(min_diff, a[i+1] - a[i]);
            }
        }

        if(!is_sorted) {
            cout << 0 << '\n';
        }else {
            cout << (min_diff+1)/2 + ((min_diff+1) % 2 != 0 ? 1 : 0) << '\n';
        }
    }
}