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

bool hasSolution(int a, int b) {
    if(2*a-b < 0 || (2*a-b) % 3 != 0) return false;
    if(a < 2*(2*a-b) /3) return false;
    return true;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int a, b;
        cin >> a >> b;
        cout << (hasSolution(a,b) || hasSolution(b,a) ? "YES\n" : "NO\n");
    }
}