#pragma once

#include "../contest/template.cpp"

struct Dsu {
    vector<int> p, h;

    Dsu(int n) : h(n), p(n) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int u) {
        return (p[u] == u) ? u : p[u] = find(p[u]);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if(u != v) {
            if(h[u] < h[v]) swap(u, v);
            p[v] = u;
            h[u] = max(h[u], h[v]+1);
        }
    }
};