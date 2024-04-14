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

    ll l, r;
    cin >> l >> r;

    ll curr = l;

    vector<ll> pow(61, 1);
    for(int i = 1; i <= 60; i++) pow[i] = pow[i-1]*2;

    vector<pll> ans;

    while(curr < r) {
        int l2 = 0, r2 = 60, best = -1;

        while(l2 <= r2) {
            int mid = (l2+r2)/2;

            if(curr % pow[mid] == 0 && pow[mid]*(curr/pow[mid]+1) <= r) {
                best = mid;
                l2 = mid+1;
            }else {
                r2 = mid-1;
            }
        }

        ans.emplace_back(pow[best]*(curr/pow[best]),pow[best]*(curr/pow[best]+1));
        curr = pow[best]*(curr/pow[best]+1);
    }

    cout << ans.size() << '\n';

    for(auto [a,b] : ans) cout << a << ' ' << b << '\n';
}