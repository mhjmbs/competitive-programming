#pragma once
#include "extended-euclidean-algorithm.hpp"

using namespace std;

using ll = long long;

namespace cp {

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

}