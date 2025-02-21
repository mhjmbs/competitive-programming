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

struct Line { ///start-hash
	mutable double k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(double x) const { return p < x; }
}; ///end-hash
struct LineContainer : multiset<Line, less<>> {
	double inf = 1/.0; //for doubles 1/.0
	double div(double a, double b) { //for doubles a/b
		return a / b; }
	bool isect(iterator x, iterator y) { ///start-hash
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	} ///end-hash
	void add(double k, double m) { ///start-hash
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p) 
			isect(x, erase(y));
	}///end-hash
	double query(ll x) { ///start-hash
		assert(!empty()); auto l = *lower_bound(x);
		return l.k * x + l.m;
	}///end-hash
};

int main() {
    fastio;

    int n;
    cin >> n;

    vector<double> p(n+1,1.0);
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    
    vector<double> dp(n+1, 0);
    dp[n] = n*p[n];

    double ans = dp[n];

    LineContainer lc;
    lc.add(p[n],dp[n]);
    
    for(int i = n-1; i > 0; i--) {
        dp[i] = max(ans, i*p[i] + p[i] * lc.query(-i));
        lc.add(p[i],dp[i]);
    }

    cout << fixed << setprecision(20) << *max_element(dp.begin(),dp.end()) << '\n';
}
