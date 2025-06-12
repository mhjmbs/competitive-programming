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

    int n, l;
    cin >> n >> l;

    vector<int> pos(n), cnt(l);
    cnt[0] = 1;
    for(int i = 1; i < n; i++) {
        int di;
        cin >> di;
        pos[i] = (pos[i-1] + di) % l;
        cnt[pos[i]]++;
    }

    if(l%3 != 0) {
        cout << 0 << '\n';
        return 0;
    }

    ll ans = 0;

    for(int i = 0; i < l/3; i++) {
        ans += ll(cnt[i])*cnt[(i+l/3) % l]*cnt[(i+2*l/3) % l];
    }

    cout << ans << '\n';
}