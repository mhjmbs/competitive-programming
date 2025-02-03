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

    int n, w;
    cin >> n >> w;

    vector<pii> blocks(n+1);
    vector<tiii> s_blocks(n);

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        blocks[i+1] = {x,y};
        s_blocks[i] = {i+1,x,y};
    }

    sort(s_blocks.begin(), s_blocks.end(), []
    (tiii a, tiii b) {
        return get<2>(a) < get<2>(b);
    });

    vector<int> count(w+1), group(n+1, 0);
    vector<vector<int>> groups(n);
    for(auto [id, x, y] : s_blocks) {
        count[x]++;
        group[id] = count[x];
        groups[group[id]].push_back(id);
    }

    vector<int> free_time(w+1, 0), group_time(n+1, 1e9+1);

    for(int g = 1; g < n; g++) {
        if(groups[g].size() < w) break;

        int curr = 0;
        for(int id : groups[g]) {
            auto [x,y] = blocks[id];
            curr = max({curr, free_time[x]+1, y});
            free_time[x] = max(free_time[x]+1, y);
        }
        group_time[g] = curr;
    }

    int q;
    cin >> q;

    while(q--) {
        int t, a;
        cin >> t >> a;
        cout << (group_time[group[a]] >= t+1 ? "Yes\n" : "No\n");
    }
}