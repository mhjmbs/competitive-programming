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

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int& ai : a) cin >> ai;

        string ans(n,'-');

        vector<int> freq(26,0);

        ans[0] = 'a';
        freq[0]++;

        for(int i = 1; i < n; i++) {
            auto it = find(freq.begin(), freq.end(), a[i]);
            char nc = 'a' + (it - freq.begin());
            freq[nc-'a']++;
            ans[i] = nc;
        }

        cout << ans << '\n';
    }
}