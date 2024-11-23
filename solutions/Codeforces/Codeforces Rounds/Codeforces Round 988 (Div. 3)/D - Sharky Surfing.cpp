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

    int t;
    cin >> t;

    while(t--) {
        int n, m, L;
        cin >> n >> m >> L;

        vector<pii> h(n);
        for(auto& [l,r] : h) cin >> l >> r;

        vector<pii> p(m);
        for(auto& [xi,pi] : p) cin >> xi >> pi;

        bool ok = true;
        ll ans = 0, k = 1;
        priority_queue<ll> prioq;

        for(int i = 0, j = 0; i < n; i++) {
            auto [l,r] = h[i];
            while(j < m) {
                auto [xi,pi] = p[j];
                if(xi >= l) break;
                prioq.push(pi);
                j++;
            }

            while(!prioq.empty() && r-l+2 > k) {
                ans++;
                k += prioq.top();
                prioq.pop();
            }

            if(r-l+2 > k) {
                ok = false;
                break;
            }
        }

        cout << (ok ? ans : -1) << '\n';
    }
}