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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());



int main() {
    fastio;

    int n;
    cin >> n;
    
    vector<ll> h(n);
    for(ll& hi : h) cin >> hi;

    vector<ll> dl(n,1e18), dr(n,1e18);

    priority_queue<pll, vector<pll>, greater<pll>> prioq;

    for(int i = 0; i < n; i++) {
        while(!prioq.empty() && prioq.top().first < h[i]) {
            auto [hj, j] = prioq.top();
            prioq.pop();
            dr[j] = i-j;
        }
        prioq.emplace(h[i],i);
    }

    while(!prioq.empty()) prioq.pop();

    for(int i = n-1; i >= 0; i--) {
        while(!prioq.empty() && prioq.top().first < h[i]) {
            auto [hj, j] = prioq.top();
            prioq.pop();
            dl[j] = j-i;
        }
        prioq.emplace(h[i],i);
    }

    ll ans = 0;

    for(int i = 0; i < n; i++) {
        if(dl[i] == 1e18 && dr[i] == 1e18) continue;
        ans += min(dl[i], dr[i]);
    }

    cout << ans << '\n';
}