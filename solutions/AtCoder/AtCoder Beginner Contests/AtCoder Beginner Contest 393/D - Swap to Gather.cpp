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

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<ll> pref(n+1, 0), cost_l(n,0), cost_r(n,0);
    
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + (s[i-1] == '1');
    }

    for(int i = 1; i < n; i++) {
        cost_l[i] = cost_l[i-1];
        if(s[i] == '0') cost_l[i] += pref[i+1];
    }
    
    for(int i = n-2; i >= 0; i--) {
        cost_r[i] = cost_r[i+1];
        if(s[i] == '0') cost_r[i] += pref[n] - pref[i];
    }

    ll ans = 1e18;

    for(int i = 0; i < n-1; i++) {
        ans = min(ans, cost_l[i] + cost_r[i+1]);
    }

    cout << ans << '\n';
}
