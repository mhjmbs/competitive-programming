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

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> x(n);
    for(int& xi : x) cin >> xi;

    vector<ll> pref(n+1, 0);
    for(int i = 1; i <= n; i++) pref[i] = pref[i-1] + x[i-1];

    ll ans = LONG_LONG_MIN;

    int l = -1 -(b-a), r = -1, curr = a;
    multiset<ll> occur;

    while(curr <= n) {
        r++;
        occur.insert(pref[r]);
        if(l >= 0) occur.erase(occur.lower_bound(pref[l]));
        l++;
        ans = max(ans, pref[curr] - *occur.begin());
        curr++;
    }

    cout << ans << '\n';
}