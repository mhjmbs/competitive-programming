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

    vector<int> p(n+1), indexOf(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        indexOf[p[i]] = i;
    }

    set<int> currI;
    int ans = INT_MAX;

    for(int pi = 1; pi <= n; pi++) {
        currI.insert(indexOf[pi]);

        if(currI.size() > k) {
            currI.erase(indexOf[pi-k]);
        }

        if(currI.size() == k) {
            ans = min(ans, *currI.rbegin() - *currI.begin());
        }
    }

    cout << ans << '\n';
}