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
        string s;
        cin >> s;

        int m;
        cin >> m;

        string l, r;
        cin >> l >> r;

        int start = 0;
        bool yes = false;

        for(int sz = 0; sz < m; sz++) {
            set<int> want;
            int min_start = s.size();
            for(int i = l[sz]-'0'; i <= r[sz]-'0'; i++) want.insert(i);

            for(int i = start; i < s.size(); i++) {
                if(want.count(s[i]-'0') == 1) {
                    want.erase(s[i]-'0');
                    min_start = i+1;
                }
            }

            if(!want.empty()) {
                yes = true;
            }else {
                start = min_start;
            }
        }

        if(yes) cout << "YES\n";
        else cout << "NO\n";
    }
}