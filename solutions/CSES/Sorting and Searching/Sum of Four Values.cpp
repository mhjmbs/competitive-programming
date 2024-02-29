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

    int n, x;
    cin >> n >> x;

    vector<ll> a(n);
    for(ll& ai : a) cin >> ai;

    set<array<ll,3>> sums;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            sums.insert({a[i]+a[j], i, j});
        }
    }

    array<ll,4> ans = {-1,-1,-1,-1};

    for(int i = 0; i < n; i++) {
        vector<array<ll,3>> currSums;
        currSums.reserve(n-1 - i);
        for(int j = 0; j < n; j++) {
            currSums.push_back({a[i]+a[j],i,j});
            sums.erase({a[i]+a[j], i, j});
        }

        for(auto [curr,i,j] : currSums) {
            auto it = sums.lower_bound({x-curr,-1,-1});
            if(it != sums.end()) {
                auto [nSum, k, l] = *it;
                if(nSum == x-curr && k != j && l != j) ans = {i,j,k,l};
            }
            it = sums.upper_bound({x-curr,INT_MAX,INT_MAX});
            if(it != sums.begin()) it--;
            if(it != sums.end()) {
                auto [nSum, k, l] = *it;
                if(nSum == x-curr && k != j && l != j) ans = {i,j,k,l};
            }
        }
    }

    if(ans[0] == -1) cout << "IMPOSSIBLE";
    else for(auto x : ans) cout << x+1 << ' ';
    cout << '\n';
}