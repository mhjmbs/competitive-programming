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

    vector<int> x(q), box(n);
    for(int& xi : x) cin >> xi;

    vector<int> ans(q);

    for(int i = 0; i < q; i++) {
        if(x[i] >= 1) ans[i] = x[i]-1;
        else ans[i] = min_element(box.begin(), box.end()) - box.begin();
        box[ans[i]]++;
    }

    for(int ans_i : ans) cout << ans_i+1 << ' ';
    cout << '\n';
}