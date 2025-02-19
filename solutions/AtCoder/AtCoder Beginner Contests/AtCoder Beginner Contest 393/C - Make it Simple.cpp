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

    int n, m;
    cin >> n >> m;

    set<pii> edges;
    int ans = 0;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u,v);

        if(u == v) {
            ans++;
        }else if(edges.count({u,v}) > 0) {
            ans++;
        }else {
            edges.emplace(u,v);
        }
    }
    
    cout << ans << '\n';
}
