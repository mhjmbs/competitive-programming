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

    int n, k;
    cin >> n >> k;  

    vector<pii> intervals(n);
    for(auto& [r,l] : intervals) cin >> l >> r;

    sort(intervals.begin(), intervals.end());

    multiset<int> rs;
    int ans = 0;

    for(auto [r,l] : intervals) {
        if(rs.empty()) {
            rs.insert(r);
            ans++;
        }else if(*rs.begin() <= l) {
            auto it = rs.upper_bound(l);
            it--;
            rs.erase(it);
            rs.insert(r);
            ans++;
        }else if(rs.size() < k) {
            rs.insert(r);
            ans++;
        }
    }

    cout << ans << '\n';
}