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
        int n;
        cin >> n;

        vector<int> a(n);
        for(int& ai : a) cin >> ai;

        vector<set<int>> free_pos(2*n+2);
        vector<vector<int>> pos(2*n+2);

        for(int i = 0; i < n; i++) {
            free_pos[a[i]].insert(i);
            pos[a[i]].push_back(i);
        }

        int ans = n;
        
        for(int num = 1; num <= 2*n; num++) {
            for(int j = pos[num].size()-1; j >= 0; j--) {
                int i = pos[num][j];
                auto it = free_pos[num-1].lower_bound(i);
                if(it != free_pos[num-1].end()) {
                    ans--;
                    free_pos[num-1].erase(it);
                    continue;
                }
                it = free_pos[num+1].lower_bound(i);
                if(it != free_pos[num+1].end()) {
                    ans--;
                    free_pos[num+1].erase(it);
                    continue;
                }
            }
        }

        cout << ans << '\n';
    }
}