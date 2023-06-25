#pragma once

#include <vector>
#include <stack>

using namespace std;

void dfs(int node, int &curr_time, vector<vector<int>> &adjacencies, vector<int> &time, vector<int> &lowlink, stack<int> &s, vector<bool> &in_s, vector<vector<int>> &sccs) {
    lowlink[node] = time[node] = curr_time;
    s.push(node);
    in_s[node] = true;

    for(int adj : adjacencies[node]) {
        if(time[adj] == -1) {
            dfs(adj, ++curr_time, adjacencies, time, lowlink, s, in_s, sccs);
        }

        if(in_s[adj]) {
            lowlink[node] = min(lowlink[node], lowlink[adj]);
        }
    }

    if(lowlink[node] == time[node]) {
        sccs.push_back({});
        int curr = -1;
        
        while(curr != node) {
            curr = s.top();
            s.pop();
            in_s[curr] = false;
            sccs.back().push_back(curr);
        }
    }
}

vector<vector<int>> tarjan(vector<vector<int>> &adjacencies) {
    vector<int> time(adjacencies.size(), -1), lowlink(adjacencies.size(), -1);
    vector<bool> in_s(adjacencies.size(), false);
    stack<int> s;
    int curr_time = 0;

    vector<vector<int>> sccs;

    for(int node = 0; node < adjacencies.size(); node++) {
        if(time[node] == -1) {
            dfs(node, curr_time, adjacencies, time, lowlink, s, in_s, sccs);
        }
    }

    return sccs;
}