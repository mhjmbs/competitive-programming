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
    
    vector<int> a(n);
    for(int& ai : a) cin >> ai;

    if(accumulate(a.begin(), a.end(), 0)%n != 0) {
        cout << -1 << '\n';
        return 0;
    }

    int target = accumulate(a.begin(), a.end(), 0)/n;

    vector<int> sum(1<<n);
    for(int mask = 1; mask < (1<<n); mask++) {
        sum[mask] = sum[mask^(1<<__lg(mask))] + a[__lg(mask)] - target;
    }

    vector<int> dp(1<<n, n+1), last(1<<n);
    dp[0] = 0;

    for(int mask = 1; mask < (1<<n); mask++) {
        for(int i = 0; i < n; i++) {
            if(!(mask&(1<<i))) continue;
            if(dp[mask] > dp[mask^(1<<i)]+(sum[mask] != 0)) {
                dp[mask] = dp[mask^(1<<i)]+(sum[mask] != 0);
                last[mask] = i;
            }
        }
    }

    vector<tiii> ans;

    ll mask = (1<<n)-1;
    while(mask != 0) {
        vector<pii> component;
        do{
            component.emplace_back(a[last[mask]], last[mask]);
            mask ^= (1<<last[mask]);
        }while(sum[mask] != 0);

        sort(component.rbegin(), component.rend());

        for(int i = 0; i < component.size()-1; i++) {
            ans.emplace_back(
                component[i].second,
                component[i+1].second,
                component[i].first-target
            );
            component[i+1].first += get<2>(ans.back());
        }
    }

    cout << dp[(1<<n)-1] << '\n';
    for(auto [x,y,z] : ans) {
        cout << x+1 << ' ' << y+1 << ' ' << z << '\n';
    }
}