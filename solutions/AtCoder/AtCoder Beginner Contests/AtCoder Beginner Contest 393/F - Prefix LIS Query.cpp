#include <algorithm>
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

const int inf = 1e9+7;

struct Query {
    int i;
    int r;
    int x;
    int ans;
};

int main() {
    fastio;
    
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(int& ai : a) cin >> ai;

    vector<Query> queries(q);
    for(int i = 0; i < q; i++) {
        int r, x;
        cin >> r >> x;
        r--;
        queries[i] = {i,r,x};
    }
    
    sort(queries.begin(), queries.end(), [](Query a, Query b) {
        return a.r < b.r;
    });

    vector<int> dp(n+1, inf);
    dp[0] = 0;
    int pref = -1;

    for(Query& q : queries) {
        while(pref < q.r) {
            pref++;
            *lower_bound(dp.begin(), dp.end(), a[pref]) = a[pref];
        }

        
        auto it = upper_bound(dp.begin(), dp.end(), q.x);
        it--;
        q.ans = it - dp.begin();
    }
    

    sort(queries.begin(), queries.end(), [](Query a, Query b) {
        return a.i < b.i;
    });

    for(Query q : queries) {
        cout << q.ans << '\n';
    }
}
