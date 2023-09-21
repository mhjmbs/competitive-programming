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

    int n;
    cin >> n;

    vector<vector<int>> m(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    bool yes = true;

    set<pii> eliminated;

    for(int k = 0; k < n; k++) {
        for(int u = 0; u < n; u++) {
            for(int v = 0; v < n; v++) {
                if(u == v || u == k || k == v) {
                    continue;
                }

                if(m[u][v] == m[u][k] + m[k][v] && eliminated.count({u,v}) == 0 && eliminated.count({v,u}) == 0) {
                    eliminated.emplace(u,v);
                }else if(m[u][v] > m[u][k] + m[k][v]){
                    yes = false;
                }
            }
        }
    }

    if(yes) {
        cout << eliminated.size() << '\n';
    }else {
        cout << -1 << '\n';
    }
}