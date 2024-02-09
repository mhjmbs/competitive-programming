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

    int n, q;
    cin >> n >> q;

    vector<int> x(n);
    for(int& xi : x) cin >> xi;

    vector<int> pref(n+1, 0);
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] ^ x[i-1];
    }

    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << (pref[b] ^ pref[a-1]) << '\n';
    }
}