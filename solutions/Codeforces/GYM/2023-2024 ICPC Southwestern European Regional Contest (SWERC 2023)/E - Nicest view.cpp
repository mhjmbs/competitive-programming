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

    int n;
    cin >> n;

    vector<ll> h(n);
    for(ll& hi : h) cin >> hi;

    frac<ll> ans = {0,1};
    priority_queue<pii, vector<pii>, greater<pii>> prioq;

    for(int i = 0; i < n; i++) {
        while(!prioq.empty() && prioq.top().first < h[i]) {
            auto [y,x] = prioq.top();
            prioq.pop();

            frac<ll> currAns = (i-1)-x;
            int slope = h[i] - h[i-1];
            currAns += frac(y-h[i-1])/slope;

            ans = max(ans, currAns);
        }
        prioq.emplace(h[i], i);
    }

    while(!prioq.empty()) prioq.pop();

    for(int i = n-1; i >= 0; i--) {
        while(!prioq.empty() && prioq.top().first < h[i]) {
            auto [y,x] = prioq.top();
            prioq.pop();

            frac<ll> currAns = x-(i+1);
            int slope = h[i+1] - h[i];
            currAns += frac(h[i+1]-y)/slope;

            ans = max(ans, currAns);
        }
        prioq.emplace(h[i], i);
    }

    ans.reduce();

    if(ans.den == 1) cout << ans.nom << '\n';
    else cout << ans.nom << '/' << ans.den << '\n';
}