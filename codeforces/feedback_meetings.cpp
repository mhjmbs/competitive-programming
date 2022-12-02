#include "bits/stdc++.h"

using namespace std;

int countSCC(int node, int& currTime, int sccCount, stack<int>& currSCC, vector<bool>& is_on_currSCC, vector<int>& time, vector<int>& lowlink, vector<vector<int>>& adjacencies) {
    time[node] = lowlink[node] = currTime;
    currSCC.push(node);
    is_on_currSCC[node] = true;

    for(int adj : adjacencies[node]) {
        if(!time[adj]) {
            sccCount += countSCC(adj, ++currTime, 0, currSCC, is_on_currSCC, time, lowlink, adjacencies);
        }

        if(is_on_currSCC[adj]) lowlink[node] = min(lowlink[node], lowlink[adj]);
    }

    if(lowlink[node] == time[node]) {
        sccCount++;
        int currV;
        do {
            currV = currSCC.top();
            currSCC.pop();
            is_on_currSCC[currV] = false;
        }while(currV != node);
    }

    return sccCount;
}

int main() {
    ios::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacencies(n+1);
    vector<bool> noMeetings(n+1, true);

    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adjacencies[u].push_back(v);
        noMeetings[u] = false;
        noMeetings[v] = false;
    }

    vector<int> time(n+1), lowlink(n+1);
    vector<bool> is_on_currSCC(400000, false);
    int currTime = 0, sccCount = 0;
    stack<int> currSCC;

    for(int i = 1; i < n+1; i++)
        if(!time[i])
            sccCount += countSCC(i, ++currTime, 0, currSCC, is_on_currSCC, time, lowlink, adjacencies);

    int ans = 2*n-sccCount;

    for(int i = 1; i < n+1; i++)
        ans -= noMeetings[i];


    cout << ans << '\n';
}