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

ll backtracking(int l1, int r1, int l2, int r2) {
    if(l1 == r1 || l2 == r2) return 0;

    int step = 1;

    while(l1 + 2*step <= r1 && l2 + 2*step <= r2 &&
          l1 % (2*step) == 0 && l2 % (2*step) == 0) {
        step *= 2;
    }


    if(l1 + 2*step > r1 || l1 % (2*step) != 0) {
        return (r2-l2)/step +
        backtracking(l1+step, r1, l2, r2) +
        backtracking(l1, l1+step, r2 - (r2-l2)%step, r2); 
    }else if(l2 + 2*step > r2 || l2 % (2*step) != 0) {
        return (r1-l1)/step +
        backtracking(l1, r1, l2+step, r2) +
        backtracking(r1 - (r1-l1)%step, r1, l2, l2+step); 
    }else {
        return (r1-l1)/step;
    }
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        cout << backtracking(l1, r1, l2, r2) << '\n';
    }
}