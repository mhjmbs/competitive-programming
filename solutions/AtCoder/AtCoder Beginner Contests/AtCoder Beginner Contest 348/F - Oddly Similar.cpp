#pragma GCC optimize("O3")
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

    int n, m;
    cin >> n >> m;

    vector<vector<short>> a(n, vector<short>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int cnt = 0;
            for(int k = 0; k < m; k++) {
                cnt ^= a[i][k] == a[j][k];
            }
            ans += cnt;
        }
    }

    cout << ans << '\n';
}