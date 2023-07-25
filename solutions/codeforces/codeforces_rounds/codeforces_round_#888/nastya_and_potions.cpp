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

ll get_cost(int potion, vector<ll> &min_cost, vector<ll> &c, vector<vector<int>> &recipes) {
    if(min_cost[potion] != -1) return min_cost[potion];

    ll brewing_cost = recipes[potion].empty() ? LONG_LONG_MAX : 0;
    for(int ingredient : recipes[potion]) {
        brewing_cost += get_cost(ingredient, min_cost, c, recipes);
    }

    return min_cost[potion] = min(c[potion], brewing_cost);
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<ll> c(n);
        for(ll &ci : c) cin >> ci;

        vector<ll> min_cost(n, -1);
        for(int i = 0, pi; i < k; i++) {
            cin >> pi;
            pi--;
            min_cost[pi] = 0;
        }

        vector<vector<int>> recipes(n);

        for(int i = 0; i < n; i++) {
            int m;
            cin >> m;

            recipes[i].resize(m);
            for(int j = 0; j < m; j++) {
                cin >> recipes[i][j];
                recipes[i][j]--;
            }
        }

        for(int i = 0; i < n; i++) {
            cout << get_cost(i, min_cost, c, recipes) << (i != n-1 ? ' ' : '\n');
        }
    }
}