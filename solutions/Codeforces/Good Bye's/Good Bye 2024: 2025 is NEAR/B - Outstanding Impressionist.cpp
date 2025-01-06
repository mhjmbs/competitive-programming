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
        
        vector<pii> intervals(n);
        vector<int> used(2*n+1), pref(2*n+1);
        
        for(auto& [l,r] : intervals) {
            cin >> l >> r;
            if(l == r) used[l]++;
        }
        
        for(int i = 1; i <=2*n; i++) {
            pref[i] = pref[i-1] + (used[i] != 0);
        }
        
        string ans(n,'0');
        
        for(int i = 0; i < n; i++) {
            auto [l,r] = intervals[i];
            
            if(l == r) {
                ans[i] = (used[l] == 1) ? '1' : '0';
            }else {
                ans[i] = (pref[r] - pref[l-1] != r-l+1) ? '1' : '0';
            }
        }
        
        cout << ans << '\n';
    }
}