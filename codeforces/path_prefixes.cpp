#include "bits/stdc++.h"

using namespace std;
using tiii = tuple<int,int,int>;
using ll = long long;

int bS(ll A, vector<ll>& sB, vector<int>& ans) {
    int l = 0, r = sB.size()-1, found = -1;
        
    while(l <= r) {
        int m = l + (r-l)/2;

        if(sB[m] <= A) {
            found = m;
            l = m+1;
        }else {
            r = m-1;
        }
    }
        
    return found-1;
}

void dfs(int node, ll A, vector<int>& ans, vector<int>& a, vector<int>& b, vector<ll>& sB, vector<vector<int>>& adjacencies) {
    sB.push_back(b[node] + sB.back());
    ans[node] = bS(A, sB, ans);

    for(int adj : adjacencies[node]) {
        dfs(adj, A+a[adj], ans, a, b, sB, adjacencies);
    }

    sB.pop_back();
}

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n+1,0), b(n+1,0);
        vector<vector<int>> adjacencies(n+1);
        
        for(int j = 2, pj; j <= n; j++) {
            cin >> pj >> a[j] >> b[j];
            adjacencies[pj].push_back(j);
        }

        vector<int> ans(n+1);
        vector<ll> sB = {0};

        dfs(1, 0, ans, a, b, sB, adjacencies);
        
        for(int i = 2; i < n+1; i++) {
            cout << ans[i];
            if(i != n) cout << ' ';
            else cout << '\n';
        }
    }
}
