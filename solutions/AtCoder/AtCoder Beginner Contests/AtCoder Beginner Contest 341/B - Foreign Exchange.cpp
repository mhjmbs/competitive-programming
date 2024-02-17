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

    vector<ll> a(n);
    for(ll& ai : a) cin >> ai;

    vector<pll> op(n-1);
    for(int i = 0; i< n-1; i++) {
        cin >> op[i].first >> op[i].second;
    }

    for(int i = 0; i < n-1; i++) {
        a[i+1] += a[i]/op[i].first * op[i].second;
    }

    cout << a[n-1] << '\n';
}