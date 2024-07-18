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

    ll n, t;
    cin >> n >> t;

    string s;
    cin >> s;

    vector<ll> l, r;
    for(int i = 0, xi; i < n; i++) {
        cin >> xi;
        if(s[i] == '0') l.push_back(xi);
        else r.push_back(xi);
    }

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    ll ans = 0;

    while(!l.empty()) {
        while(!r.empty() && l.back() < r.back()) r.pop_back();
        ll i = lower_bound(r.begin(), r.end(), l.back()-2*t) - r.begin();
        ans += r.size() - i; 
        l.pop_back();
   }

    cout << ans << '\n';
}