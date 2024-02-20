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

ll digitSum(int num) {
    int ans = 0;
    while(num > 0) {
        ans += num % 10;
        num /= 10;
    }
    return ans;
}

int main() {
    fastio;

    int t;
    cin >> t;

    vector<int> ans(2*1e5+1, 0);
    for(int num = 1; num < ans.size(); num++) {
        ans[num] += ans[num-1] + digitSum(num);
    }

    while(t--) {
        int n;
        cin >> n;
        cout << ans[n] << '\n';
    }
}