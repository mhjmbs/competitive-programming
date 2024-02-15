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

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for(int& ai : a) cin >> ai;

    ll ans = 0;

    for(int i = 0; i < n-1; i++) {
        if(a[i] + a[i+1] <= x) continue;

        if(x-a[i] >= 0) {
            ans += a[i+1] - (x-a[i]);
            a[i+1] = x-a[i];
        }else {
            ans += a[i+1];
            a[i+1] = 0;
        }

        if(a[i] > x) {
            ans += a[i]-x;
            a[i] = x;
        }
    }

    cout << ans << '\n';
}