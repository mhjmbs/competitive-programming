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

    int t;
    cin >> t;

    while(t--) {
        int x, y;
        cin >> y >> x;

        ll sq = max(x,y);
        ll curr = sq*sq;

        if(sq % 2 == 1) {
            int x2 = sq, y2 = 1;
            curr -= y - y2;
            curr -= x2 - x;
        }else {
            int x2 = 1, y2 = sq;
            curr -= x - x2;
            curr -= y2 - y;
        }

        cout << curr << '\n';
    }
}