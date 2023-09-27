#pragma once

#include <bits/stdc++.h>

using namespace std;

class Dsu {
    vector<int> root;
    vector<int> max_depth;

    public:

    Dsu(int node_count) {
        max_depth.resize(node_count, 0);
        root.resize(node_count);

        for(int u = 0; u < root.size(); u++) {
            root[u] = u;
        }
    }

    int find(int u) {
        return root[u] == u ? u : root[u] = find(root[u]);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);

        if(u != v) {
            if(max_depth[u] < max_depth[v]) {
                swap(u, v);
            }

            root[v] = u;
            max_depth[u] = max(max_depth[u], max_depth[v]+1);
        }
    }
};