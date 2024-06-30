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

    int n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    string ans(m, ' ');

    copy(a.begin(), a.end(), ans.end()-n);

    for(int i = m-1-n; i >= 0; i--) {
        for(int c = 0; c < 26; c++) {
            if((ans[i+n]-'a' + c)%26 == (b[i+n]-'a')%26) {
                ans[i] = 'a'+c;
                break;
            }
        }
    }

    cout << ans << '\n';
}