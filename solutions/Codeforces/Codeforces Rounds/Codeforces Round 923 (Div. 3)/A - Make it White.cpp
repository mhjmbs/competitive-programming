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
        int fb = -1, lb = -1;

        int n;
        cin >> n;

        string s;
        cin >> s;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'B') {
                if(fb == -1) fb = i;
                lb = i;
            }
        }

        if(fb == -1) cout << 0 << '\n';
        else cout << lb - fb + 1 << '\n';
    }


}