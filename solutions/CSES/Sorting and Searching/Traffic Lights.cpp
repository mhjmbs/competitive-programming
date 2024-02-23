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

    int x, n;
    cin >> x >> n;

    set<pii> intervals;
    intervals.emplace(0, x);

    multiset<int> dist;
    dist.insert(x);

    while(n--) {
        int pi;
        cin >> pi;

        auto it = intervals.upper_bound({pi,INT_MAX});
        it--;

        auto [l,r] = *it;
        intervals.erase(it);

        if(l == 0 && r == x) dist.erase(dist.lower_bound(r-l));
        else if(l == 0 || r == x) dist.erase(dist.lower_bound(r-l+1));
        else dist.erase(dist.lower_bound(r-l+2));

        if(l <= pi-1) {
            intervals.emplace(l, pi-1);
            if(l == 0) dist.insert(pi);
            else dist.insert(pi-l+1);
        }
        if(pi+1 <= r) {
            intervals.emplace(pi+1, r);
            if(r == x) dist.insert(r-pi);
            else dist.insert(r-pi+1);
        }

        cout << *dist.rbegin() << ' ';
    }
    cout << '\n';
}