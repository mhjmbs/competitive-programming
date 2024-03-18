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

    ll n, c;
    cin >> n >> c;

    vector<ll> a(n);
    for(ll& ai : a) cin >> ai;

    vector<ll> left(n, 0);
    left[0] = a[0];
    for(int i = 1; i < n; i++) left[i] = max(0LL, left[i-1] + a[i] - c);

    ll ans = LONG_LONG_MAX, pos = -1;

    for(int i = 0; i < n; i++) {
        ll m = left[i]/c;
        if(i+m < n && m < ans) {
            ans = m;
            pos = i;
        }
    }

    if(pos != -1) cout << pos << '\n';
    else cout << "impossible\n";
}