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

    vector<int> k(n);
    for(int& ki : k) cin >> ki;

    int l = 0, r = -1, ans = 0;
    set<int> occur;

    for(int ki : k) {
        while(occur.count(ki) > 0) {
            occur.erase(k[l]);
            l++;
        }
        occur.insert(ki);
        r++;
        ans = max(ans, r-l+1);
    }

    cout << ans << '\n';
}