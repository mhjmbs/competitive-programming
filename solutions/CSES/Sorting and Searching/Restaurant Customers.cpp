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

    priority_queue<pii, vector<pii>, greater<pii>> prioq;

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        prioq.emplace(a,1);
        prioq.emplace(b,-1);
    }

    int ans = 0;
    int in = 0;

    while(!prioq.empty()) {
        auto [curr, event] = prioq.top();
    
        while(!prioq.empty() && prioq.top().first == curr) {
            in += prioq.top().second;
            prioq.pop();
        }

        ans = max(ans, in);
    }

    cout << ans << '\n';
}