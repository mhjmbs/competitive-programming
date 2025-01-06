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

ll m = 998244353;

ll binExp(ll a, ll b) {
    a %= m;
    ll ans = 1;
    while(b > 0) {
        if(b&1) ans = ans * a % m;
        a = a*a % m;
        b >>= 1;
    }
    return ans;
}

ll inv(ll x) {
    return binExp(x, m-2);
}

int main() {
    fastio;
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, q;
        cin >> n >> q;
        
        vector<ll> a(n+1), b(n+1);
        vector<ll> sa(n+1), sb(n+1);
        map<ll,int> la, lb;
        
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];
        
        sa = a;
        sb = b;
        
        sort(sa.begin()+1, sa.end());
        sort(sb.begin()+1, sb.end());
        
        for(int i = 1; i <= n; i++) {
            la[sa[i]] = i;
            lb[sb[i]] = i;
        }
        
        ll ans = 1;
        
        for(int i = 1; i <= n; i++) {
            ans = ans*min(sa[i], sb[i]) % m;
        }
        
        cout << ans << ' ';
        
        while(q--) {
            int o, x;
            cin >> o >> x;
            
            vector<ll>& v = (o == 1) ? a : b;
            vector<ll>& w = (o != 1) ? a : b;
            
            vector<ll>& sv = (o == 1) ? sa : sb;
            vector<ll>& sw = (o != 1) ? sa : sb;
            
            map<ll,int>& lv = (o == 1) ? la : lb;
            map<ll,int>& lw = (o != 1) ? la : lb;
            
            int sx = lv[v[x]];
            
            ans = ans*inv(min(sv[sx], sw[sx])) % m;
            
            lv[v[x]]--;
            if(sv[lv[v[x]]] != v[x]) lv.erase(v[x]);
            
            sv[sx]++;
            v[x]++;
            if(lv.count(v[x]) == 0) lv[v[x]] = sx;
            
            ans = ans*min(sv[sx], sw[sx]) % m;
            
            cout << ans << ' ';
        }
        
        cout << '\n';
    }
}