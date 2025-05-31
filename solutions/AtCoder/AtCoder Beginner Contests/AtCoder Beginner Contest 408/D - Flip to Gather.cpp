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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());



int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        if(count(s.begin(), s.end(), '1') == 0) {
            cout << 0 << '\n';
            continue;
        }

        vector<int> pref(n+1);
        for(int i = 1; i <= n; i++) pref[i] = pref[i-1] + (s[i-1] == '1');

        vector<int> dpr(n);
        dpr[0] = s[0] == '0';

        int cl = -1;
        for(int i = 1; i < n; i++) {
            if(s[i] == '1') {
                dpr[i] = dpr[i-1];
                if(cl == -1) {
                    dpr[i] = min(pref[i], dpr[i]); 
                    cl = i;
                }
            }else {
                dpr[i] = dpr[i-1]+1;
                if(cl != -1) cl = -1;
            }
        }

        vector<int> dpl(n);
        dpl[n-1] = s[n-1] == '0';
        
        int cr = -1;
        for(int i = n-2; i >= 0; i--) {
            if(s[i] == '1') {
                dpl[i] = dpl[i+1];
                if(cr == -1) {
                    dpl[i] = min(pref[n]-pref[i+1], dpl[i]); 
                    cr = i;
                }
            }else {
                dpl[i] = dpl[i+1]+1;
                if(cr != -1) cr = -1;
            }
        }

        int ans = 1e9;
        for(int i = 0; i < n; i++) ans = min(ans, dpr[i]+dpl[i]-(s[i] == '0'));

        cout << ans << '\n';
    }
}