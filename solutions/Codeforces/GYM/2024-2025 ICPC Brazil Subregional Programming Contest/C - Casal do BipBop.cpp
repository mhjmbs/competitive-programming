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

static std::mt19937_64 twister(1337);

ll rng() {
    return rand();
}

template<typename T, typename Cmp=less<T>>
struct rmq_t : private Cmp {
	int N = 0;
	vector<vector<T>> table; 
	const T& min(const T& a, const T& b) const { return Cmp::operator()(a, b) ? a : b; }
	rmq_t() {}
	rmq_t(const vector<T>& values) : N(int(values.size())), table(__lg(N) + 1) {
		table[0] = values;
		for (int a = 1; a < int(table.size()); ++a) {
			table[a].resize(N - (1 << a) + 1);
			for (int b = 0; b + (1 << a) <= N; ++b) 
				table[a][b] = min(table[a-1][b], table[a-1][b+(1<<(a-1))]); 
		}
	}
	T query(int a, int b) const { 
		int lg = __lg(b - a);
		return min(table[lg][a], table[lg][b - (1 << lg) ]);
	}
};

struct suffix_array_t { ///start-hash
	int N, H; vector<int> sa, invsa, lcp;
	rmq_t<pair<int, int>> rmq;
	bool cmp(int a, int b) { return invsa[a+H] < invsa[b+H]; }
	void ternary_sort(int a, int b) {
		if (a == b) return;
		int md = sa[a+rng() % (b-a)], lo = a, hi = b;
		for (int i = a; i < b; ++i) if (cmp(sa[i], md))
			swap(sa[i], sa[lo++]);
		for (int i = b-1; i >= lo; --i) if (cmp(md, sa[i]))
			swap(sa[i], sa[--hi]);
		ternary_sort(a, lo);
		for (int i = lo; i < hi; ++i) invsa[sa[i]] = hi-1;
		if (hi-lo == 1) sa[lo] = -1;
		ternary_sort(hi, b);
	}
	suffix_array_t() {} ///end-hash
	template<typename I> ///start-hash
	suffix_array_t(I begin, I end): N(int(end-begin)+1), sa(N) {
		vector<int> v(begin, end); v.push_back(INT_MIN);
		invsa = v; iota(sa.begin(), sa.end(), 0);
		H = 0; ternary_sort(0, N);
		for(H = 1; H <= N; H *= 2) for(int j=0, i=j; i!=N; i=j)
				if (sa[i] < 0) {
					while (j < N && sa[j] < 0) j += -sa[j];
					sa[i] = -(j - i);
				} else {j = invsa[sa[i]] + 1; ternary_sort(i, j);}
		for (int i = 0; i < N; ++i) sa[invsa[i]] = i;
		lcp.resize(N-1); int K = 0;
		for (int i = 0; i < N-1; ++i) {
			if(invsa[i] > 0) while(v[i+K] == v[sa[invsa[i]-1]+K])++K;
			lcp[invsa[i]-1] = K; K = max(K - 1, 0);
		}
		vector<pair<int, int>> lcp_index(N-1);
		for (int i = 0; i < N-1; ++i) lcp_index[i] = {lcp[i], 1+i};
		rmq = rmq_t<pair<int, int>>(std::move(lcp_index));
	} ///end-hash
	auto rmq_query(int a, int b) const {return rmq.query(a,b);}
	auto get_split(int a, int b) const {return rmq.query(a,b-1);}
	int get_lcp(int a, int b) const { ///start-hash
		if (a == b) return N -1 - a;
		a = invsa[a], b = invsa[b];
		if (a > b) swap(a, b);
		return rmq_query(a, b).first;
	} ///end-hash
};

template<typename T>
struct frac {
    T nom;
    T den;

    frac(T nom, T den) : nom{nom}, den{den} {}
    frac(T nom) : frac(nom,1) {}

    static pair<frac,frac> equalize(frac a, frac b) {
        T cmn = lcm(a.den, b.den);
        a = {a.nom*(cmn/a.den), cmn};
        b = {b.nom*(cmn/b.den), cmn};
        return {a,b};
    }

    void reduce() {
        T GCD = gcd(nom,den);
        nom /= GCD;
        den /= GCD;
    }

    frac inverse() const { return {den,nom}; }

    frac& operator+=(frac other) {
        auto [a,b] = equalize(*this, other);
        return *this = {a.nom+b.nom, a.den};
    }
    frac& operator*=(frac other) { return *this = {nom*other.nom, den*other.den}; }
    frac& operator-=(frac other) { return *this += -other; }
    frac& operator/=(frac other) { return *this *= other.inverse(); }

    frac operator-() const { return {-nom,den}; }

    frac operator+(frac other) const { return frac(*this) += other; }
    frac operator*(frac other) const { return frac(*this) *= other; }
    frac operator-(frac other) const { return frac(*this) -= other; }
    frac operator/(frac other) const { return frac(*this) /= other; }

    bool operator==(frac other) const {
        auto[a,b] = equalize(*this, other);
        return a.nom == b.nom;
    }

    strong_ordering operator<=>(frac other) const {
        auto [a,b] = equalize(*this, other);
        if(a.nom > b.nom) return strong_ordering::greater;
        if(a.nom < b.nom) return strong_ordering::less;
        return strong_ordering::equal;
    }
};

int main() {
    fastio;

    ll n;
    cin >> n;

    vector<int> v(n);
    for(int& vi : v) cin >> vi;

    suffix_array_t sa(v.begin(), v.end());
    vector<ll> haha(n+1);

    for(int i = 1; i < n; i++) {
        int l = i+1, r = n, r_count = 0;

        while(l <= r) {
            int mid = (l+r)/2;

            if(sa.get_lcp(sa.sa[i], sa.sa[mid]) == sa.lcp[i] && sa.get_lcp(sa.sa[i+1], sa.sa[mid]) != sa.lcp[i]) {
                r_count = mid-i;
                l = mid+1;
            }else {
                r = mid-1;
            }
        }

        l = 1, r = i;
        ll l_count = 0;

        while(l <= r) {
            int mid = (l+r)/2;

            if(sa.get_lcp(sa.sa[mid], sa.sa[i+1]) == sa.lcp[i]) {
                l_count = i-mid+1;
                r = mid-1;
            }else {
                l = mid+1;
            }
        }

        haha[sa.lcp[i]] += 2 * (l_count * r_count);

    }

    for(int i = 1; i <= n; i++) haha[i]++;

    frac<ll> ans = 0;

    for(int i = 0; i <= n; i++) {
        ans += frac<ll>{haha[i],n*n}*i;
        ans.reduce();
    }

    cout << ans.nom << '/' << ans.den << '\n';
}