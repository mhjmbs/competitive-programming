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

    int t;
    cin >> t;

    while(t--) {
        ll n, m;
        cin >> n >> m;

        vector<ll> a(n);
        for(ll& ai : a) cin >> ai;
        
        int l = 0, r = n-1;

        string s;
        cin >> s;

        for(char c : s) {
            if(c == 'L') l++;
            else r--;
        }

        reverse(s.begin(), s.end());

        vector<ll> ans;
        ans.reserve(n);
        ll prod = 1;

        for(char c : s) {
            if(c == 'L') {
                l--;
                prod = prod * a[l] % m;
            }else {
                r++;
                prod = prod * a[r] % m;
            }

            ans.push_back(prod);
        }

        reverse(ans.begin(), ans.end());

        for(ll x : ans) cout << x << ' ';
        cout << '\n';
    }
}