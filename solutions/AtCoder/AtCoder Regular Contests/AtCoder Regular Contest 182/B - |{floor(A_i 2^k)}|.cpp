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

int n, k, printed;
vector<int> b;

void solve(int curr) {
    if(printed == n) return;

    if(curr == 0) {
        int toPrint = 0;
        for(int i = 0; i < k; i++) {
            toPrint <<= 1;
            toPrint += b[i];
        }
        cout << toPrint << ' ';
        printed++;
        return;
    }

    solve(curr-1);
    b[curr] = !b[curr];
    solve(curr-1);
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> k;

        b.assign(k, 1);
        printed = 0;

        solve(k-1);
        while(printed < n) {
            cout << 1 << ' ';
            printed++;
        }
        cout << '\n';
    }
}