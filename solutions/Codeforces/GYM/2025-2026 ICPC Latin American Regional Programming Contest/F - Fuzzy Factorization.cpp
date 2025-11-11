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

map<ll,ll> factorize(ll num) {
    map<ll,ll> factors;
    for(ll i = 2; i*i <= num; i++) {
        while(num%i == 0) {
            factors[i]++;
            num /= i;
        }
    }
    if(num > 1) factors[num]++;
    return factors;
}

int main() {
    fastio;

    string s;
    cin >> s;

    int n = s.size();

    ll num = 0;
    for(int i = 0; i < min(n,10); i++) {
        num *= 10;
        num += s[i]-'0';
    }

    map<ll,ll> factors = factorize(num);
    if(n > 10) {
        factors[2] += max(n-10,0);
        factors[5] += max(n-10,0);
    }

    cout << factors.size() << '\n';
    for(auto [p,e] : factors) cout << p << ' ' << e << '\n';
}