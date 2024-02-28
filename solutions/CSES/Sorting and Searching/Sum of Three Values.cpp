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

    int n, x;
    cin >> n >> x;

    vector<pii> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }

    sort(a.begin(), a.end());

    array<int,3> ans = {-1,-1,-1};

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int curr = a[i].first + a[j].first;
            int k = lower_bound(a.begin()+j+1, a.end(), make_pair(x-curr,-1)) - a.begin();
            if(k != n && a[k].first == x-curr) ans = {a[i].second, a[j].second, a[k].second};
        }
    }

    if(ans[0] == -1) cout << "IMPOSSIBLE\n";
    else cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
}