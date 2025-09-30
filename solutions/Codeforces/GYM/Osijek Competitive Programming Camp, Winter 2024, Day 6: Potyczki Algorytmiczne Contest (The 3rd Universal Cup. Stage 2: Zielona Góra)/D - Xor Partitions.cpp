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

const ll m = 1e9+7;

ll add(ll a, ll b) {
    ll ans = a+b;
    return ans < m ? ans : ans-m;
}

int main() {
    fastio;

    array<ll,64> pot, pot_m;
    pot[0] = pot_m[0] = 1;
    for(int i = 1; i < 64; i++) {
        pot[i] = 2*pot[i-1];
        pot_m[i] = add(pot_m[i-1], pot_m[i-1]);
    }

    int n;
    cin >> n;

    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    ll dp = a[1] % m;
    vector<vector<ll>> pref(64, vector<ll>(2));
    for(int i = 0; i < 64; i++) {
        if(a[1]&pot[i]) pref[i][1] = add(pref[i][1], pot_m[i]);
        else pref[i][0] = add(pref[i][0], pot_m[i]);
    }

    for(int i = 2; i <= n; i++) {
        ll ndp = 0;
        vector<vector<ll>> npref(64, vector<ll>(2));
        for(int j = 0; j < 64; j++) {
            if(a[i]&pot[j]) {
                npref[j][0] = add(npref[j][0], pref[j][1]);
                npref[j][1] = add(npref[j][1], pref[j][0]);
                npref[j][1] = add(npref[j][1], dp*pot_m[j] % m);
            }else {
                npref[j][0] = add(npref[j][0], pref[j][0]);
                npref[j][1] = add(npref[j][1], pref[j][1]);
                npref[j][0] = add(npref[j][0], dp*pot_m[j] % m);
            }
            ndp = add(ndp, npref[j][1]);
        }
        swap(ndp,dp);
        swap(npref,pref);
    }

    cout << dp << '\n';
}