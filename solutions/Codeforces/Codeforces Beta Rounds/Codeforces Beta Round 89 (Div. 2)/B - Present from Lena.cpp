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

int n;

string line(int l) {
    string ans(1 + 4*n, ' ');

    for(int i = ans.size()/2, curr = l; curr >= 0; i += 2, curr--) {
        ans[i] = '0' + curr;
    }

    for(int i = ans.size()/2, curr = l; curr >= 0; i -= 2, curr--) {
        ans[i] = '0' + curr;
    }

    return ans;
}

int main() {
    fastio;

    cin >> n;

    for(int i = 0; i <= n; i++) {
        string line_i = line(i);
        cout << line_i.substr(0, line_i.find_last_not_of(' ')+1) << '\n';
    }

    for(int i = n-1; i >= 0; i--) {
        string line_i = line(i);
        cout << line_i.substr(0, line_i.find_last_not_of(' ')+1) << '\n';
    }
}