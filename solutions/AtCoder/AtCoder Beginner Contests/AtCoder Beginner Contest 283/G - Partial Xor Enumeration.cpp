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

    ll n, l, r;
    cin >> n >> l >> r;
    l--, r--;

    vector<ll> a;

    for(int i = 0; i < n; i++) {
        ll curr;
        cin >> curr;

        for(ll& ai : a) {
            curr = min(curr, curr^ai);
        }

        if(curr != 0) a.push_back(curr);
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < i; j++) {
            if((a[j]^a[i]) < a[i]) a[i] ^= a[j];
        }
    }

    while(l <= r) {
        ll ans = 0;
        for(int i = 0; i < 64; i++) {
            if(l & (1ll<<i)) ans ^= a[i];
        }

        cout << ans << ' ';

        l++;
    }
    cout << '\n';
}