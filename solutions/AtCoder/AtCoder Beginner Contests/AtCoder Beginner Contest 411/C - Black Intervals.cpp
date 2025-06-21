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

    int n, q;
    cin >> n >> q;

    vector<int> box(n+2);

    int ans = 0;

    while(q--) {
        int ai;
        cin >> ai;

        tiii curr = {box[ai-1],box[ai],box[ai+1]};    
        if(curr == make_tuple(0,0,0) || curr == make_tuple(1,1,1)) {
            ans++;
        }else if(curr == make_tuple(0,1,0) || curr == make_tuple(1,0,1)) {
            ans--;
        }

        box[ai] = !box[ai];
        cout << ans << '\n';
    }
}