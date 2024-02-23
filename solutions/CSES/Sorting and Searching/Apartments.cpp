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

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n), b(m);
    for(ll& ai : a) cin >> ai;
    for(ll& bi : b) cin >> bi;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    int ans = 0;

    while(i < n && j < m) {
        if(a[i]-k <= b[j] && b[j] <= a[i]+k) {
            ans++;
            i++;
            j++;
        }else if(b[j] < a[i]-k) {
            j++;
        }else {
            i++;
        }
    }

    cout << ans << '\n';
}