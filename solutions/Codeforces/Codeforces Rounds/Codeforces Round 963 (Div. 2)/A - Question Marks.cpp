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

    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int A = 0, B = 0, C = 0, D = 0;

        int ans = 4*n;

        for(char c : s) {
            if(c == 'A') A++;
            if(c == 'B') B++;
            if(c == 'C') C++;
            if(c == 'D') D++;
        }

        ans -= max(n-A, 0);
        ans -= max(n-B, 0);
        ans -= max(n-C, 0);
        ans -= max(n-D, 0);

        cout << ans << '\n';
    }
}