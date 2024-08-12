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

ll binExp(ll a, ll b, ll m) {
    ll ans = 1;
    while(b > 0) {
        if(b&1) ans = ans*a % m;
        a = a*a % m;
        b >>= 1;
    }
    return ans;
}

int main() {
    fastio;

    int n, q;
    cin >> n >> q;

    vector<int> p(q), v(q), status(q, 0);

    for(int i = 0; i < q; i++) {
        cin >> p[i] >> v[i];
    }

    bool ok = true;

    for(int i = 0; i < q; i++) {
        for(int j = i+1; j < q; j++) {
            if(v[i] <= v[j]) continue;
            if(p[i] == p[j]) {
                ok = false;
            }else if(p[i] < p[j]) {
                if(status[i] == 1 || status[j] == -1) ok = false;
                status[i] = -1;
                status[j] = 1;
            }else {
                if(status[i] == -1 || status[j] == 1) ok = false;
                status[i] = 1;
                status[j] = -1;
            }
        }
    }

    if(!ok) cout << 0 << '\n';
    else cout << binExp(2, count(status.begin(), status.end(), 0), 998244353) << '\n';
}