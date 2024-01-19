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

    int n;
    cin >> n;

    vector<int> a(n);
    for(int& ai : a) cin >> ai;

    vector<int> h(n, 1), h2(n, 1);

    for(int i = 0, count = 1; i < n; i++, count++) {
        count = min(count, a[i]);
        h[i] = count;
    }

    int ans = 1;

    for(int i = n-1, count = 1; i >= 0; i--, count++) {
        count = min(count, a[i]);
        h2[i] = count;
        ans = max(ans, 2*min(h[i], h2[i])-1);
    }

    cout << ans/2+1 << '\n';
}