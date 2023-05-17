#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using ull = unsigned long long;

ull modmul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}

ull pollard(ull n) {
    auto f = [n](ull x, ull k) { return modmul(x, x, n) + k;};
    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    while (t++ % 40 || gcd(prd, n) == 1) {
        if (x == y) x = ++i, y = f(x, i);
        if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
        x = f(x, i), y = f(f(y,i), i);
    }
    return gcd(prd, n);
}

ull modpow(ull b, ull e, ull mod) {
    ull ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2)
    if (e & 1) ans = modmul(ans, b, mod);
    return ans;
}

bool isPrime(ull n) {
    if(n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    vector<ull> A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    ull s = __builtin_ctzll(n-1), d = n >> s;
    for(ull a : A) {
        ull p = modpow(a % n, d, n), i = s;
        while(p != 1 && p != n-1 && a % n && i--)
        p = modmul(p, p, n);
        if (p != n-1 && i != s) return 0;
    }
    return 1;
}

vector<ull> factor(ull n) {
    if (n == 1) return {};
    if (isPrime(n)) return {n};
    ull x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), r.begin(), r.end());
    return l;
}

int main() {
    fastio;

    int n;
    cin >> n;

    while(n--) {
        int a, b;
        cin >> a >> b;

        set<ull> diff;
        vector<ull> factor_a = factor(a), factor_b = factor(b);
        for(ull x : factor_a) diff.insert(x);
        for(ull x : factor_b) diff.insert(x);
        cout << diff.size() << '\n';
    }
}