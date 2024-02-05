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

bool containsDigit(int x, vector<int>& d) {
    bool ans = false;
    while(x != 0) {
        int digit = x%10;
        for(int di : d) ans = ans || digit == di;
        x /= 10;
    }
    return ans;
}

int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    vector<int> d(k);
    for(int& di : d) cin >> di;

    while(containsDigit(n, d)) n++;
    
    cout << n << '\n';
}