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

int n;
vector<int> p;
ll g1 = 0, g2 = 0;
ll ans = LONG_LONG_MAX;

void backtracking(int i) {
    if(i == n) {
        ans = min(ans, abs(g1-g2));
        return;
    }

    g1 += p[i];
    backtracking(i+1);
    g1 -= p[i];

    g2 += p[i];
    backtracking(i+1);
    g2 -= p[i];
}

int main() {
    fastio;

    cin >> n;

    p.resize(n);
    for(int& pi : p) cin >> pi;

    backtracking(0);

    cout << ans << '\n';
}