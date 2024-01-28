#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 //
#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)
 
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;
 
using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

ll binExp(ll a, ll b, ll m) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1) ans = ans* a % m;
        a = a*a %m;
        b >>= 1;
    }
    return ans;
}

ll mod(ll a, ll m) {
    return (a%m + m) % m;
}

template <ll p, ll m>
class Hash {
    int n;
    vector<ll> h;
    inline static vector<ll> pPow = {1};
    inline static vector<ll> invPow = {1};
    inline static ll invMod = binExp(p, m-2, m);
    
    public:

    Hash(const string& s) : n{s.size()}, h(s.size()+1, 0) {
        pPow.reserve(n);
        invPow.reserve(n);
        while(pPow.size() < n) pPow.push_back( mod(pPow.back()*p, m) );
        while(invPow.size() < n) invPow.push_back( mod(invPow.back()*invMod, m) );
        
        for(int i = 0; i < n; i++) {
            h[i+1] = mod(h[i] + (s[i] - 'a' + 1) * pPow[i], m);
        }
    }
    
    int substr(int l, int r) {
        return mod( mod(h[r+1] - h[l], m) * invPow[l], m);
    }
};

int main() {
    fastio;
 
    string s, b, e;
    cin >> s >> b >> e;
    
    const ll p = 31, m = 1e9+7;

    Hash<p,m> hs(s);
    ll hb = Hash<p,m>(b).substr(0, b.size()-1);
    ll he = Hash<p,m>(e).substr(0, e.size()-1);

    int ans = 0;

    for(int sz = max(b.size(),e.size()); sz <= s.size(); sz++) {
        set<ll> hashes;
        for(int i = 0; i <= s.size() - sz; i++) {
            if(hs.substr(i, i + b.size() - 1) == hb &&
               hs.substr(i + sz - e.size(), i + sz-1) == he) {
                   hashes.insert(hs.substr(i, i+sz-1));
            }
        }
        ans += hashes.size();
    }

    cout << ans << '\n';
}