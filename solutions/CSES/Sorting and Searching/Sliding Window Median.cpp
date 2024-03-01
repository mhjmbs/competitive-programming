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

    int n, k;
    cin >> n >> k;

    vector<int> x(n);
    for(int& xi : x) cin >> xi;

    ordered_multiset os;

    int l = 0, r = -1;

    while(r-l+1 < k) {
        r++;
        os.insert(x[r]);
    }

    while(r < n) {
        cout << *os.find_by_order((k-1)/2) << ' ';

        os.erase(os.upper_bound(x[l]));
        l++;
        r++;
        if(r != n) os.insert(x[r]);
    }
    cout << '\n';
}