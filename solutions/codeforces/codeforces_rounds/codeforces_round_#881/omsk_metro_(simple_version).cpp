#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
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
        int n;
        cin >> n;

        vector<pii> poss = {{-1, -1}, {0, 1}}, finish = {{-1,-1}, {0, 1}};

        while(n--) {
            char q;
            cin >> q;

            if(q == '+') {
                int v, x;
                cin >> v >> x;
                poss.push_back(poss[v]);
                finish.push_back(finish[v]);

                if(x == 1) {
                    finish.back().first++;
                    finish.back().second++;
                    poss.back().second = max(poss.back().second, finish.back().second);
                }else {
                    finish.back().second--;
                    finish.back().first--;
                    poss.back().first = min(poss.back().first, finish.back().first);
                }

                poss.back().first = min(poss.back().first, x);
                poss.back().second = max(poss.back().second, x);
                finish.back().first = min(finish.back().first, x);
                finish.back().second = max(finish.back().second, x);
            }else {
                int u, v, k;
                cin >> u >> v >> k;

                if(poss[v].first <= k && k <= poss[v].second || k == 0) {
                    cout << "YES\n";
                }else {
                    cout << "NO\n";
                }
            }
        }
    }
}