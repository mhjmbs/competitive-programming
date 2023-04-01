#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    vector<tiii> edges(m);
    for(int i = 0, u, v, c; i < m; i++) {
        cin >> u >> v >> c;
        edges[i] = {u,v,c};
    }

    bool yes = false;
    int next;
    vector<ll> dist(n+1, ll(1e17));
    vector<int> p(n+1, -1);

    for(int r = 0; r < n; r++) {
        for(tiii edge : edges) {
            int u, v, c;
            tie(u, v, c) = edge;

            if(dist[u] + c < dist[v]) {
                dist[v] = dist[u] + c;
                p[v] = u;   
                if(r == n-1) {
                    yes = true;
                    next = v;
                }
            }
        }
    }

    if(yes) {
        cout << "YES\n";

        stack<int> s;
        set<int> occur;
        while(occur.count(next) == 0) {
            s.push(next);
            occur.insert(next);
            next = p[next];
        }

        vector<int> nc = {next};
        while(s.top() != next) {
            nc.push_back(s.top());
            s.pop();
        }
        nc.push_back(next);

        for(int i = 0; i < nc.size(); i++) {
            cout << nc[i];
            if(i != nc.size()-1) cout << ' ';
            else cout << '\n';
        }

    }else {
        cout << "NO\n";
    }
}