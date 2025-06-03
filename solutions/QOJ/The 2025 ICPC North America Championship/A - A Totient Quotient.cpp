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

vector<int> pr, lp(10001);

ll pow(ll a, ll b) {
    ll ans = 1;
    while(b > 0) ans *= a;
    return ans;
}

vector<int> factorize(int x) {
    vector<int> result;
    while(x > 1) {
        result.push_back(lp[x]);
        x /= lp[x];
    }
    return result;
}


int main() {
    fastio;

    for(int i = 2; i <= 10000; i++) {
        if(lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for(int p : pr) {
            if(p > lp[i] || i*p > 10000) break;
            lp[i*p] = p;
        }
    }

    int a, b;
    cin >> a >> b;
    
    vector<int> ap(10001), bp(10001);
    for(int p : factorize(a)) ap[p]++;
    for(int p : factorize(b)) bp[p]++;

    ll m = 1, n = 1;

    for(int p = 10000; p > 1; p--) {
        if(abs(ap[p]-bp[p]) % 2 == 0) {
            if(ap[p] > bp[p]) {
                m *= pow(p, (ap[p]-bp[p]+2)/2);
                n *= p;
            }else if(ap[p] < bp[p]) {
                m *= p;
                n *= pow(p, (bp[p]-ap[p]+2)/2);
            }
        }else {
            if(ap[p] > bp[p]) {
                m *= pow(p, (ap[p]-bp[p]+1)/2);
                for(int j : factorize(p-1)) bp[j]++;
            }else {
                n *= pow(p, (bp[p]-ap[p]+1)/2);
                for(int j : factorize(p-1)) ap[j]++;
            }
        }
    }

    cout << m << ' ' << n << '\n';
}