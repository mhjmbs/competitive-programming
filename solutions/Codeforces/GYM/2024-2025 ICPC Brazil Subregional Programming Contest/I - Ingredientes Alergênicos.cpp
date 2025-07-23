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

vector<int> lp;
vector<int> sets(1e6);
const ll m = 1e9+7;

template <typename T>
vector<T> linear_sieve(T n) {
    vector<T> lp(n+1), p;
    for(T i = 2; i <= n; i++) {
        if(lp[i] == 0) {
            lp[i] = i;
            p.push_back(i);
        }
        for(int j = 0; i*p[j] <= n; j++) {
            lp[i*p[j]] = p[j];
            if(lp[i] == p[j]) break;
        }
    }
    return lp;
}

vector<int> factor(int x) {
    vector<int> p;
    while(x > 1) {
        p.push_back(lp[x]);
        x /= lp[x];
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    return p;
}

void subsets(int i, vector<int>& p, int curr) {
    if(i == p.size()) {
        sets[curr]++;
        return;
    }
    subsets(i+1, p, curr);
    subsets(i+1, p, curr*p[i]);
}

int inc_exc(int i, vector<int>& p, int curr, int cnt) {
    if(i == p.size()) {
        return (cnt % 2 != 0) ? sets[curr] : -sets[curr];
    }
    int ans = 0;
    ans += inc_exc(i+1, p, curr, cnt);
    ans += inc_exc(i+1, p, curr*p[i], cnt+1);
    return ans;
}

ll bin_exp(ll a, ll b) {
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
    
    lp = linear_sieve<int>(1e6);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int vi;
        cin >> vi;
        vector<int> p = factor(vi);
        subsets(0, p, 1);
    }

    sets[1] = 0;

    int q;
    cin >> q;

    while(q--) {
        int xi;
        cin >> xi;

        vector<int> p = factor(xi);
        int ans = inc_exc(0, p, 1, 0);

        cout << bin_exp(2, n-ans) << '\n';
    }
}