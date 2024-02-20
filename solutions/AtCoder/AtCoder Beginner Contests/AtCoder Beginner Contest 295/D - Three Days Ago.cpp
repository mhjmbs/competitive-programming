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

    string s;
    cin >> s;

    int n = s.size();

    vector<ll> oldDP(1<<11, 0);

    ll ans = 0;

    for(int i = 0; i < n; i++) {
        vector<ll> newDP(1<<11, 0);
        for(int mask = 0; mask < (1<<11); mask++) {
            newDP[mask] += oldDP[mask^(1<<(s[i]-'0'))];
        }
        newDP[1<<(s[i]-'0')]++;
        ans += newDP[0];
        swap(newDP, oldDP);
    }

    cout << ans << '\n';
}