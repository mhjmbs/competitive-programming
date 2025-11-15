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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());



int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n, a;
        cin >> n >> a;

        vector<int> v(n);
        for(int& vi : v) cin >> vi;
        sort(v.begin(), v.end());

        int high = upper_bound(v.begin(), v.end(), a) - v.begin();
        int low = lower_bound(v.begin(), v.end(), a) - v.begin() - 1;

        int b = (low+1 >= n-high) ? a-1 : a+1;
        
        cout << b << '\n';
    }
}