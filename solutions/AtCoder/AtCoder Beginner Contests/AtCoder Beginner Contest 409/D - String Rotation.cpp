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

        int il = n-1;

        for(int i = 0; i < n-1; i++) {
            if(s[i] > s[i+1]) {
                il = i;
                break;
            }
        }

        int ir = n-1;
        
        for(int i = il+1; i < n; i++) {
            if(s[il] >= s[i]) ir = i;
            else break;
        }
        
        s.insert(ir+1, string(1,s[il]));
        s.erase(il,1);

        cout << s << '\n';
    }
    
}