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
        int n, q;
        cin >> n >> q;

        multiset<int> a;
        for(int i = 0; i < n; i++) {
            int ai;
            cin >> ai;
            a.insert(ai);
        }

        while(q--) {
            int c;
            cin >> c;

            int ans = 0;
            stack<pii> rollback;

            for(int i = 29; i >= 0; i--) {
                if(!(c&(1<<i))) continue;
                auto it = a.lower_bound(1<<i);
                int add, remove;
                if(it == a.end()) {
                    add = 0;
                    remove = *a.rbegin();
                    ans += (1<<i)-*a.rbegin();
                }else {
                    add = (*it)^(1<<i);
                    remove = *it;
                }
                a.insert(add);
                a.erase(a.lower_bound(remove));
                rollback.emplace(add,remove);
            }

            cout << ans << '\n';

            while(!rollback.empty()) {
                auto [remove, add] = rollback.top();
                rollback.pop();
                a.insert(add);
                a.erase(a.lower_bound(remove));
            }
        }
    }
}