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

tlll pos_egcd(ll a, ll b) {
    if(b == 0) {
        return {a, 1, 0};
    }else {
        auto [gcd, x, y] = pos_egcd(b, a%b);
        return {gcd, y, x-(a/b)*y};
    }
}

tlll egcd(ll a, ll b) {
    auto [gcd, x, y] = pos_egcd(abs(a), abs(b));
    x = (a >= 0) ? x : -x;
    y = (b >= 0) ? y : -y;
    return {gcd, x, y};
}

template<ll m>
struct modint {
    ll n;

    modint() : n{0} {}
    modint(ll n) : n{n} { mod(); }

    void mod() { n = (n%m + m) % m; }
    modint inv() { return modint( get<1>(egcd(n,m)) ); }

    modint operator+=(modint other) { return *this = n+other.n; }
    modint operator*=(modint other) { return *this = n*other.n; }
    modint operator-=(modint other) { return *this += -other.n; }
    modint operator/=(modint other) { return *this *= other.inv(); }
    modint operator%=(modint other) { return *this = (n%other.n + other.n) % other.n; }

    modint operator-() const { return -n; }

    friend modint operator+(modint lhs, modint rhs) { return lhs += rhs; }
    friend modint operator*(modint lhs, modint rhs) { return lhs *= rhs; }
    friend modint operator-(modint lhs, modint rhs) { return lhs -= rhs; }
    friend modint operator/(modint lhs, modint rhs) { return lhs /= rhs; }
    friend modint operator%(modint lhs, modint rhs) { return lhs %= rhs; }

    bool operator==(modint other) const {return n == other.n; }
    strong_ordering operator<=>(modint other) const {
        if(n > other.n) return strong_ordering::greater;
        if(n < other.n) return strong_ordering::less;
        return strong_ordering::equal;
    }

    friend ostream& operator<<(ostream& os, modint obj) {
        os << obj.n;
        return os;
    }
    friend istream& operator>>(istream& os, modint& obj) {
        os >> obj.n;
        obj.mod();
        return os;
    }
};

int main() {
    fastio;

    const ll m = 998244353;

    modint<m> n;
    int k;
    cin >> n >> k;

    vector<modint<m>> dp(k+1);
    dp[0] = 1;

    for(int i = 1; i <= k; i++) {
        dp[i] = dp[i-1]/(n*n) + dp[i-1]*(n-1)*(n-1)/(n*n) + 2*(1-dp[i-1])/(n*n);
    }

    modint<m> ans = dp[k] + (n*(n+1)/2 - 1) * (1-dp[k]) / (n-1);
    cout << ans << '\n';
}