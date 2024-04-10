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

    int n;
    cin >> n;

    vector<pii> v(n);
    for(auto& [x,y] : v) cin >> x >> y;

    for(int i = 0; i < n; i++) {
        int ans = 0;
        int id = i;
        for(int j = 0; j < n; j++) {
            auto [x1,y1] = v[i];
            auto [x2,y2] = v[j];
            if( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) > ans) {
                ans = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
                id = j;
            }
        }

        cout << id+1 << '\n';
    }
}