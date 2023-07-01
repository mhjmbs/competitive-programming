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

    int n, m;
    cin >> n >> m;

    multiset<int> p;
    for(int i = 0, inp; i < n; i++) {
        cin >> inp;
        p.insert(inp);
    }

    vector<pii> dis(m); // discount / min price
    for(int i = 0; i < m; i++) {
        cin >> dis[i].second;
    }
    for(int i = 0; i < m; i++) {
        cin >> dis[i].first;
    }

    sort(dis.rbegin(), dis.rend());

    ll ans = 0;

    for(int i = 0; i < dis.size(); i++) {
        auto it = p.lower_bound(dis[i].second);

        if(it != p.end()) {
            ans += *it - dis[i].first;
            p.erase(it);
        }
    }

    for(int pi : p) ans += pi;

    cout << ans << '\n';
}