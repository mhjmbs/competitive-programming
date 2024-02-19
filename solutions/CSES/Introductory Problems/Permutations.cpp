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

    if(n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    vector<int> p;
    p.reserve(n);

    for(int i = 2; i <= n; i += 2) p.push_back(i);
    for(int i = 1; i <= n; i += 2) p.push_back(i);

    for(int pi : p) cout << pi << ' ';
    cout << '\n';
}