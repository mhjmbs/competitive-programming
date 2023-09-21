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

    string s;
    cin >> s;

    int ans = 0;

    for(int i = 0; i < s.size(); i++) {
        int l = i, r = i;
        int curr_ans = 0;

        while(0 <= l && r < s.size() && s[l] == s[r]) {
            curr_ans += (l == r) ? 1 : 2;
            l--;
            r++;
        }

        ans = max(ans, curr_ans);

        l = i, r = i+1;
        curr_ans = 0;

        while(0 <= l && r < s.size() && s[l] == s[r]) {
            curr_ans += 2;
            l--;
            r++;
        }

        ans = max(ans, curr_ans);
    }

    cout << ans << '\n';
}