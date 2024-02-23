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

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for(int& ai : a) cin >> ai;

        vector<int> x(n);
        for(int& xi : x) cin >> xi;

        priority_queue<pii,vector<pii>, greater<pii>> prioq;

        for(int i = 0; i < n; i++) {
            prioq.emplace(abs(x[i]),a[i]);
        }

        ll time = 0;

        bool yes = true;

        while(!prioq.empty() && yes) {
            int currK = k;

            while(currK > 0 && !prioq.empty()) {
                auto [pos, hp] = prioq.top();
                prioq.pop();

                if(pos-time <= 0) {
                    yes = false;
                    break;
                }

                if(hp > currK) {
                    hp -= currK;
                    currK = 0;
                    prioq.emplace(pos, hp);
                }else {
                    currK -= hp;
                }
            }

            time++;
        }

        cout << (yes ? "YES\n" : "NO\n");
    }
}