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

template<typename T>
T egcd(T a, T b, T &x, T &y) {
	if (!a) { x = 0, y = 1; return b; }
	T g = egcd(b % a, a, y, x);
	x -= y * (b/a); return g;
}
ull modmul(ull a, ull b, ull M) { ///start-hash
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
} ///end-hash
ull modpow(ull b, ull e, ull mod) { ///start-hash
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
} ///end-hash
bool isPrime(ull n) { ///start-hash
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	vector<ull> A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
	ull s = __builtin_ctzll(n-1), d = n >> s; ///end-hash
	for(ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a % n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}
ull pollard(ull n) { ///start-hash
	auto f = [n](ull x, ull k) { return modmul(x, x, n) + k; };
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while (t++ % 40 || gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x, i);
		if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
		x = f(x, i), y = f(f(y, i), i);
	}
	return gcd(prd, n);
} ///end-hash
vector<ull> factor(ull n) { ///start-hash
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ull x = pollard(n); auto l = factor(x), r = factor(n/x);
	l.insert(l.end(), r.begin(), r.end());
	return l;
} ///end-hash

set<ll> vis;
vector<ull> factors;
ll ans = -1;

void get_div(int i, ll curr, ll ai) {
    if(vis.count(curr) == 1) return;
    
    if(i == factors.size()) {
        if(curr != ai) ans = curr;
        vis.insert(curr);
        return;
    }

    get_div(i+1, curr, ai);
    get_div(i+1, curr/factors[i], ai);
}

int main() {
    fastio;

    int n;
    cin >> n;

    ll x = 1;
    vector<ll> a(n);
    for(ll& ai : a) {
        cin >> ai;
        x = lcm(x, ai);
    }
    sort(a.begin(), a.end());

    set<ull> diff;

    for(ll& ai : a) {
        factors = factor(ai);
        diff.insert(factors.begin(), factors.end());
        get_div(0, ai, ai);
    }

    if(ans != -1) cout << x << ' ' << ans << '\n';
    else if(vis.count(x) == 0) cout << x << ' ' << x << '\n';
    else if(diff.size() == 1) cout << x*a[1] << ' ' << x*a[1] << '\n';
    else cout << "*\n";
}