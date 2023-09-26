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
using pci = pair<char,int>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;



int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> a(n);
    for(int &ai : a) cin >> ai;

    string s;
    cin >> s;

    map<pci, ll> count;
    vector<vector<ll>> me(3, vector<ll>(3, 0));

    ll ans = 0;

    for(int i = 0; i < n; i++) {
        count[{s[i],a[i]}]++;

        if(s[i] == 'E') {
            me[0][a[i]] += count[{'M',0}];
            me[1][a[i]] += count[{'M',1}];
            me[2][a[i]] += count[{'M',2}];
        } else if(s[i] == 'X') {
            if(a[i] == 0) {
                ans += me[0][0];
                ans += me[2][0];
                ans += me[0][2];
                ans += me[2][2];
                
                ans += 2 * me[1][0];
                ans += 2 * me[0][1];
                ans += 2 * me[1][1];

                ans += 3 * me[2][1];
                ans += 3 * me[1][2];
            }else if(a[i] == 1) {
                ans += 2 * me[0][0];
                ans += 2 * me[0][1];
                ans += 2 * me[1][0];

                ans += 3 * me[2][0];
                ans += 3 * me[0][2];
            }else {
                ans += me[0][0];
                ans += me[0][2];
                ans += me[2][0];

                ans += 3 * me[1][0];
                ans += 3 * me[0][1];
            }
        }
    }

    cout << ans << '\n';
}