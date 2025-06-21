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

    vector<ll> a(n);
    for(ll& ai : a) cin >> ai;

    vector<ll> pref(n+1);
    for(int i = 1; i <= n; i++) pref[i] = pref[i-1] + a[i-1];

    ll ans = 0;

    for(int i = 0; i < n; i++) {
        ans += a[i]*(pref[n]-pref[i+1]);
    }

    cout << ans << '\n';
}