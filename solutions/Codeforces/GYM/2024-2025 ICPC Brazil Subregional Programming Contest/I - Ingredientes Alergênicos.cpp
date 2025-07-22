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

vector<int> primes, pfac;

vector<int> run_sieve(int N) {
	vector<int>mu(N+1,-1), phi(N+1);
	pfac.resize(N+1);
    primes.reserve(N+1); mu[1] = phi[1] = 1;
	for (int i = 2; i <= N; ++i) {
		if (!pfac[i])
			pfac[i] = i, phi[i] = i-1, primes.push_back(i);
		for (int p : primes) {
			if (p > N/i) break;
			pfac[p * i] = p; mu[p * i] *= mu[i];
			phi[p * i] = phi[i] * phi[p];
			if (i % p == 0) {
				mu[p * i] = 0; phi[p * i] = phi[i] * p;
				break;
			}
		}
	} return primes;
}

template<typename T>
vector<pair<T, int>> prime_factorize(T n) {
	vector<pair<T, int>> factors;
	while(n != 1) {
		T p = pfac[n];
		int exp = 0;
		do {
			n /= p;
			++exp;
		} while(n % p == 0);
		factors.push_back({p, exp});
	}
	for (T p : primes) {
		if (p * p > n) break;
		if (p * p == 0) {
			factors.push_back({p, 0});
			do {
				n /= p;
				++factors.back().second;
			} while(n % p == 0);
		}
	}
	if (n > 1) factors.push_back({n, 1});
	return factors;
}

vector<int> sets(1e6+1, 0);

void compute(vector<pii>& factors, int curr, int i) {
    if(i == factors.size()) {
        sets[curr]++;
        return;
    }
    compute(factors, curr*factors[i].first, i+1);
    compute(factors, curr, i+1);
}

int inc_exc(vector<pii>& factors, int curr, int i, int count) {
    int ans = 0;
    if(i == factors.size()) {
        if(count == 0) return 0;
        return count%2 != 0 ? sets[curr] : -sets[curr];
    }
    ans += inc_exc(factors, curr*factors[i].first, i+1, count+1);
    ans += inc_exc(factors, curr, i+1, count);

    return ans;
}

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
    cin >> n;

    run_sieve(1e6);

    for(int i = 0; i < n; i++) {
        int vi;
        cin >> vi;
        vector<pii> factors = prime_factorize(vi);
        compute(factors, 1, 0);
    }

    cin >> q;
    while(q--) {
        int xi;
        cin >> xi;

        vector<pii> factors = prime_factorize(xi);
        int ans = inc_exc(factors, 1, 0, 0);
        cout << binExp(2, n-ans, 1e9+7) << '\n';
    }
}