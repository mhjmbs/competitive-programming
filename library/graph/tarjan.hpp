#pragma once

#include <bits/stdc++.h>

using namespace std;

void dfs(int u, int &t, vector<vector<int>> &g, vector<int> &tin, vector<int> &low, stack<int> &s, vector<int> &in_s, vector<vector<int>> &sccs) {
    low[u] = tin[u] = t++;
    s.push(u);
    in_s[u] = true;

    for(int v : g[u]) {
        if(tin[v] == -1) {
            dfs(v, t, g, tin, low, s, in_s, sccs);
            low[u] = min(low[u], low[v]);
        }else if(in_s[v]) {
            low[u] = min(low[u], tin[v]);
        }
    }

    if(low[u] == tin[u]) {
        sccs.push_back({});
        int curr = -1;     
        while(curr != u) {
            curr = s.top();
            s.pop();
            in_s[curr] = false;
            sccs.back().push_back(curr);
        }
    }
}

vector<vector<int>> tarjan(vector<vector<int>> &g) {
    vector<int> tin(g.size(), -1);
    vector<int> low(g.size(), -1);
    vector<int> in_s(g.size());
    stack<int> s;
    int t = 0;

    vector<vector<int>> sccs;

    for(int u = 0; u < g.size(); u++) {
        if(tin[u] == -1) {
            dfs(u, t, g, tin, low, s, in_s, sccs);
        }
    }

    return sccs;
}