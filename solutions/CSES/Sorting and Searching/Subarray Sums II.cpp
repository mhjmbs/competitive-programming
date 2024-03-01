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

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for(int& ai : a) cin >> ai;

    vector<ll> pref(n+1, 0);
    for(int i = 1; i <= n; i++) pref[i] = pref[i-1] + a[i-1];

    map<ll,int> occur;

    ll ans = 0;

    for(int i = 0; i <= n; i++) {
        ans += occur[pref[i]-x];
        occur[pref[i]]++;
    }

    cout << ans << '\n';
}