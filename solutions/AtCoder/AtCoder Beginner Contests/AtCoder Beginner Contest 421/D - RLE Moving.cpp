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

    map<char,ll> di = {
        {'U',-1},
        {'D',1},
        {'L',0},
        {'R',0}
    };

    map<char,ll> dj = {
        {'U',0},
        {'D',0},
        {'L',-1},
        {'R',1}
    };

    ll i0, j0, i1, j1;
    cin >> i0 >> j0 >> i1 >> j1;

    ll n, m, l;
    cin >> n >> m >> l;

    vector<vector<pair<char,ll>>> moves {
        vector<pair<char,ll>>(m),
        vector<pair<char,ll>>(l)
    };

    for(auto& [si, ai] : moves[0]) cin >> si >> ai;
    for(auto& [si, ai] : moves[1]) cin >> si >> ai;

    ll ans = 0;
    int i = 0, j = 0;

    while(i < m && j < l) {
        auto& [s0, a0] = moves[0][i];
        auto& [s1, a1] = moves[1][j];
        ll k = min(a0, a1);

        // cout << k << ' ' << nxt_i0 << ' ' << nxt_j0 << ' ' << nxt_i1 << ' ' << nxt_j1 <<'\n';
        // cout << "(" << i0 << "," << j0 << ") (" << i1 << "," << j1 << ")\n";

        if(s0 == s1 && i0 == i1 && j0 == j1) {
            ans += k;
        }else if(s0 != s1) {
            ll ki = -1;
            if(i0 == i1) {
                ki = (di[s0]-di[s1] != 0) ? 0 : -2;
            }else if(di[s0]-di[s1] != 0 && (i1-i0) % (di[s0]-di[s1]) == 0) {
                ki = (i1-i0) / (di[s0]-di[s1]);
            }
            ll kj = -1;
            if(j0 == j1) {
                kj = (dj[s0]-dj[s1] != 0) ? 0 : -2;
            }else if(dj[s0]-dj[s1] != 0 && (j1-j0) % (dj[s0]-dj[s1]) == 0) {
                kj = (j1-j0) / (dj[s0]-dj[s1]);
            }

            if(ki != -1 && kj != -1 && (
                ki == -2 && (1 <= kj && kj <= k) ||
                kj == -2 && (1 <= ki && ki <= k) ||
                ki == kj && (1 <= ki && ki <= k) && (1 <= kj && kj <= k))) {
                ans++;
            }
        }

        i0 += di[s0]*k;
        j0 += dj[s0]*k;
        i1 += di[s1]*k;
        j1 += dj[s1]*k;

        a0 -= k;
        a1 -= k;
        if(a0 == 0) i++;
        if(a1 == 0) j++;
    }

    cout << ans << '\n';
}