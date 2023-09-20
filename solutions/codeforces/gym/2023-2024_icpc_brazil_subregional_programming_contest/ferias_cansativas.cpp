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

    int d, c, r;
    cin >> d >> c >> r;

    queue<int> q;

    for(int i = 0, ci; i < c; i++) {
        cin >> ci;
        q.push(ci);
    }

    for(int i = 0, ri; i < r; i++) {
        cin >> ri;
        d += ri;
    }

    int ans = r;

    while(!q.empty() && q.front() <= d) {
        d -= q.front();
        q.pop();
        ans++;
    }

    cout << ans << '\n';
}