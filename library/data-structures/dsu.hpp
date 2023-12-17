#pragma once

#include <bits/stdc++.h>

using namespace std;

class Dsu {
    vector<int> parent;
    vector<int> height;

    public:

    Dsu(int n) {
        height.resize(n, 0);
        parent.resize(n, -1);
    }

    int find(int u) {
        return parent[u] == -1 ? u : parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);

        if(u != v) {
            if(height[u] < height[v]) swap(u, v);

            parent[v] = u;
            height[u] = max(height[u], height[v]+1);
        }
    }
};