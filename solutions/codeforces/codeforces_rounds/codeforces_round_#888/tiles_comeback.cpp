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
        int n, k;
        cin >> n >> k;

        vector<int> c(n+1);
        for(int i = 1; i <= n; i++) {
            cin >> c[i];
        }

        bool yes = false;

        if(c[1] == c[n]) {
            int color_count = 0;
            
            for(int i = 1; i <= n; i++) {
                if(c[i] == c[1]) color_count++;
            }
            
            yes = color_count >= k;
        }else {
            int c1 = 0, last = 1;
            
            for(int i = 1; i <= n; i++) {
                if(c[i] == c[1]) {
                    c1++;
                    last = i;
                    if(c1 == k) break;
                }
            }

            int cn = 0, first = n;
            
            for(int i = n; i > 0; i--) {
                if(c[i] == c[n]) {
                    cn++;
                    first = i;
                    if(cn == k) break;
                }
            }

            yes = last < first && c1 == k && cn == k;           
        }

        if(yes) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }
}