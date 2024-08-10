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

    int n;
    cin >> n;

    vector<vector<vector<int>>> a(n+1, vector<vector<int>>(n+1, vector<int>(n+1, 0)));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                cin >> a[i][j][k];
            }
        }
    }

    vector<vector<vector<int>>> pref(n+1, vector<vector<int>>(n+1, vector<int>(n+1, 0)));

    for(int j = 1; j <= n; j++) {
        for(int k = 1; k <= n; k++) {
            for(int i = 1; i <= n; i++) {
                pref[i][j][k] = pref[i-1][j][k] + a[i][j][k];
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int k = 1; k <= n; k++) {
            for(int j = 1; j <= n; j++) {
                pref[i][j][k] += pref[i][j-1][k];
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                pref[i][j][k] += pref[i][j][k-1];
            }
        }
    }

    int q;
    cin >> q;

    while(q--) {
        int li, ri, lj, rj, lk, rk;
        cin >> li >> ri >> lj >> rj >> lk >> rk;
        int ans = pref[ri][rj][rk]
        - pref[ri][lj-1][rk] + pref[ri][lj-1][lk-1] + pref[li-1][lj-1][rk] - pref[li-1][lj-1][lk-1]
        - pref[li-1][rj][rk] - pref[ri][rj][lk-1] + pref[li-1][rj][lk-1];
        cout << ans << '\n';
    }
}