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

    vector<int> a(n);
    vector<vector<int>> occur(2e5+1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        occur[a[i]].push_back(i);
    }

    ll ans = 0;

    for(ll i = 0; i < n; i++) {
        auto it = upper_bound(occur[a[i]].begin(), occur[a[i]].end(), i);
        ll right = it != occur[a[i]].end() ? *it-1-i : n-1-i;
        ans += (i+1)*(right+1);
    }

    cout << ans << '\n';
}