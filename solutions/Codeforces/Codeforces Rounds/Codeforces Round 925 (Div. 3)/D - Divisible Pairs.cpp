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
        ll n, x, y;
        cin >> n >> x >> y;

        vector<pll> a(n);
        for(pll& p : a) {
            int ai;
            cin >> ai;
            p.first = ai%x;
            p.second = ai%y;
        }

        map<pll,int> occur;
        ll ans = 0;
        for(int i = n-1; i >= 0; i--) {
            if(occur.count(make_pair((x - a[i].first) % x, (a[i].second)%y)) != 0) {
                ans += occur[make_pair((x - a[i].first)%x, (a[i].second)%y)];
            }
            occur[a[i]]++;
        }

        cout << ans << '\n';
    }
}