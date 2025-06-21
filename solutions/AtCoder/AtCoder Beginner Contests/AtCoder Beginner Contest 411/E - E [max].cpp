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

const ll m = 998244353;

ll bin_exp(ll a, ll b) {
    a %= m;
    ll ans = 1;
    while(b > 0) {
        if(b&1) ans = ans*a % m;
        a = a*a % m;
        b >>= 1;
    }
    return ans;
}

int inv(ll n) {
    return bin_exp(n, m-2);
}

ll sum(ll a, ll b) {
    return (a+b < m) ? a+b : a+b-m;
}

ll sub(ll a, ll b) {
    return (a-b >= 0) ? a-b : a-b+m;
}

int main() {
    fastio;

    int n;
    cin >> n;

    map<int,vector<int>> dices;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 6; j++) {
            int aij;
            cin >> aij;
            dices[aij].push_back(i);
        }
    }
    
    ll npg = 1, npge = 1;
    vector<int> ge(n);
    ll ans = 0;

    for(auto it = dices.rbegin(); it != dices.rend(); it++) {
        auto [num, dices] = *it;

        for(int dice : dices) {
            npge = npge*inv((6-ge[dice])*inv(6)) % m;
            ge[dice]++;
            npge = npge*(6-ge[dice])*inv(6) % m;
        }

        ll pg = sub(1,npg);
        ll prob = sub(1, sum(pg,npge));

        ans = (ans + num*prob) % m;
        npg = npge;
    }

    cout << ans << '\n';
}