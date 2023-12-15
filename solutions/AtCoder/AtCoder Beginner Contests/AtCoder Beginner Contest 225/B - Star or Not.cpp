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

    vector<vector<int>> adjacencies(n);

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }

    bool yes = false;

    for(int node = 0; node < n; node++) {
        if(adjacencies[node].size() == n-1) {
            yes = true;
        }
    }

    cout << (yes ? "Yes" : "No") << '\n';
}