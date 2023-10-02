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

int digit_sum(int x) {
    int ans = 0;
    while(x > 0) {
        ans += x%10;
        x /= 10;
    }
    return ans;
}

int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    vector<int> occur(1e6+1, 0);

    for(int i = 0, curr; i < n; i++) {
        cin >> curr;
        occur[curr]++;
    }

    int removed = 0;
    int curr = 1e6;

    while(removed < k && curr >= 0) {

        removed += occur[curr];
        occur[curr - digit_sum(curr)] += occur[curr];
        occur[curr] = 0;

        curr--;
   }

   cout << digit_sum(curr+1) << '\n';
}