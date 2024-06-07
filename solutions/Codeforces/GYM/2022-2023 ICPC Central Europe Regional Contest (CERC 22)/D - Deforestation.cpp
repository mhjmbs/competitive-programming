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

ll w, ans = 0;

int dfs() {
    int m, n;
    cin >> m >> n;

    vector<int> children(n);
    ll sum = 0;

    for(int i = 0; i < n; i++) {
        children[i] = dfs();
        sum += children[i];
    }

    sort(children.rbegin(), children.rend());

    for(int i = 0; i < n; i++) {
        if(sum > w) {
            sum -= children[i];
            ans++;
        }
    }

    m += sum;
    ans += m/w;
    m %= w;

    return m;
}

int main() {
    fastio;

    cin >> w;

    ans += dfs() != 0 ? 1 : 0;

    cout << ans << '\n';
}