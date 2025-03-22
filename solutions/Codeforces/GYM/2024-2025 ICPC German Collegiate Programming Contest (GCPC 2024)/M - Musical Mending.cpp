#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <queue>

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

    vector<int> t(n);
    for(int& ti : t) cin >> ti;
    
    ll ans = 1e18;

    priority_queue<pll,vector<pll>,greater<pll>> prioq;

    for(int i = 0; i < n; i++) {
        prioq.emplace(t[i]-i,i);
    }

    int t0 = -1000000;
    ll smaller_count = n;
    ll smaller_cost = 0;
    ll bigger_count = 0;
    ll bigger_cost = 0;
    
    for(int i = 0; i < n; i++) {
        smaller_cost += t[i] - (t0+i);
    }

    while(!prioq.empty()) {
        auto [nt0,i] = prioq.top();
        prioq.pop();
        
        bigger_cost += bigger_count*(nt0-t0);
        smaller_cost -= smaller_count*(nt0-t0);

        smaller_count--;
        bigger_count++;

        ans = min(ans, smaller_cost + bigger_cost);
        t0 = nt0;
    }

    cout << ans << '\n';
}
