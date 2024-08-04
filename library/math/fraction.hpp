#pragma once

#include <bits/stdc++.h>

using namespace std;

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