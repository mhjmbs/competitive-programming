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

    vector<ll> x(n), p(n);
    for(ll& xi : x) cin >> xi;
    for(ll& pi : p) cin >> pi;

    vector<ll> pref(n+1, 0);
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + p[i-1];
    }

    int q;
    cin >> q;

    while(q--) {
        ll l, r;
        cin >> l >> r;

        int left = lower_bound(x.begin(), x.end(), l) - x.begin();
        int right = upper_bound(x.begin(), x.end(), r) - x.begin() - 1;

        if(left <= right) cout << pref[right+1] - pref[left] << '\n';
        else cout << 0 << '\n';
    }   
}