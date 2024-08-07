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

    vector<int> box(n, 0), a(n), w(n);

    for(int& ai : a) cin >> ai;
    for(int& wi : w) cin >> wi;

    ll ans = 0;

    for(int i = 0; i < n; i++) {
        if(w[i] > box[a[i]]) swap(w[i], box[a[i]]);
        ans += w[i];
    }

    accumulate(box.begin(), box.end(), ans);

    cout << ans << '\n';
}