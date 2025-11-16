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

int pos_mod(int a, int m) {
    return (a%m+m) % m;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int& ai : a) cin >> ai;

        vector<pii> sides(n);
        sides[0] = {n-1, pos_mod(1,n)};
        sides[n-1] = {pos_mod(n-2,n),0};

        for(int i = 1; i < n-1; i++) {
            sides[i] = {i-1,i+1};
        }

        priority_queue<pii, vector<pii>, greater<pii>> prioq;
        for(int i = 0; i < n; i++) prioq.emplace(a[i],i);
        
        ll ans = 0;
        while(prioq.size() > 1) {
            auto [ai, i] = prioq.top();
            prioq.pop();

            sides[sides[i].first].second = sides[i].second;
            sides[sides[i].second].first = sides[i].first;

            ans += min(a[sides[i].first],a[sides[i].second]);
        }

        cout << ans << '\n';
    }
}