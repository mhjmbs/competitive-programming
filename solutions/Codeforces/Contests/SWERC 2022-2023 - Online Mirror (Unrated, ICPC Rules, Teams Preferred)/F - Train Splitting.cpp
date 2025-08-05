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
        int n, m;
        cin >> n >> m;

        int k = 2;

        vector<int> dg(n+1);
        vector<tiii> e(m);

        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            if(u > v) swap(u,v);
            dg[u]++, dg[v]++;
            e[i] = {u,v,1};
        }

        int target = min_element(dg.begin()+1, dg.end()) - dg.begin();

        int l1 = -1, l2 = -1;
        for(int i = 0; i < m; i++) {
            auto& [u,v,c] = e[i];
            if(u != target && v != target) continue;
            c = 2;
            l2 = l1;
            l1 = i;
        }

        if(dg[target] == n-1) {
            k++;
            get<2>(e[l1]) = 3;
        }

        cout << k << '\n';
        for(auto [u,v,c] : e) cout << c << ' '; 
        cout << '\n';
    }
}