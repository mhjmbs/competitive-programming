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

using ordered_set = tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    fastio;

    int n;
    cin >> n;

    ordered_set intervals, indexes;

    for(int i = 1; i <= n; i++) {
        ll xi;
        cin >> xi;
        intervals.insert({xi,xi});
        indexes.insert({i,i});
    }

    int q;
    cin >> q;

    ll ans = 0;

    while(q--) {
        ll t, g;
        cin >> t >> g;

        auto it = indexes.upper_bound({t,LONG_LONG_MAX});
        it--;
        
        auto [il, ir] = *it;
        auto [l, r] = *intervals.find_by_order(indexes.order_of_key({il,ir}));

        indexes.erase({il,ir});
        intervals.erase({l,r});

        int t_pos = l + (t - il);
        
        if(t_pos < g) {
            if(t != il) {
                indexes.insert({il,t-1});
                intervals.insert({l, t_pos-1});
                il = t;
                l = t_pos;
            }

            while(true) {
                auto it = indexes.lower_bound({il,ir});
                if(it == indexes.end()) break;

                auto[nil, nir] = *it;
                auto[nl, nr] = *intervals.find_by_order(indexes.order_of_key(*it));

                if(nl-g >= ir-il+1) break;

                ans += (nl-1 - r) * (r-l+1);
                
                l += (nl-1 - r);
                r = nr;
                ir = nir;

                indexes.erase({nil,nir});
                intervals.erase({nl,nr});
            }

            ans += ((g - l) * (r-l+1));
            r += g-l;
            l = g;
        }else if(t_pos > g) {
            if(t != ir) {
                indexes.insert({t+1,ir});
                intervals.insert({t_pos+1, r});
                ir = t;
                r = t_pos;
            }

            while(true) {
                auto it = indexes.upper_bound({il,ir});
                if(it == indexes.begin()) break;
                it--;

                auto[nil, nir] = *it;
                auto[nl, nr] = *intervals.find_by_order(indexes.order_of_key(*it));

                if(g - nr >= ir-il+1) break;

                ans += (l - (nr+1)) * (r-l+1);

                r -= (l - (nr+1));
                l = nl;
                il = nil;

                indexes.erase({nil,nir});
                intervals.erase({nl,nr});
            }

            ans += ((r - g) * (ir-il+1));
            l -= r-g;
            r = g;
        }

        indexes.insert({il,ir});
        intervals.insert({l,r});
    }

    cout << ans << '\n';
}