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

    vector<vector<int>> l(m, vector<int>(26, 0));

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < m; j++) {
            l[j][s[j]-'a']++;
        }
    }

    string ans(m, '-');

    for(int i = 0; i < m; i++) {
        int occur = 0;
        for(int j = 0; j < 26; j++) {
            if(l[i][j] > occur) {
                occur = l[i][j];
                ans[i] = 'a'+j;
            }
        }
    }
    
    cout << ans << '\n';
}