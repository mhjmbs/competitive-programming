#include "bits/stdc++.h"

using namespace std;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--) {
        int n, m, x;
        cin >> n >> m >> x;

        vector<int> bindex(n);
        priority_queue<pii> bprio;

        for(int i = 0, temp; i < n; i++) {
            cin >> temp;
            bprio.emplace(temp, i);
        }

        vector<int> h(m, 0);
        priority_queue<pii, vector<pii>, greater<pii>> hprio;

        for(int i = 0; i < m; i++) {
            hprio.emplace(0,i);
        }

        while(!bprio.empty()) {
            h[hprio.top().second] += bprio.top().first;
            bindex[bprio.top().second] = hprio.top().second;
            hprio.emplace(h[hprio.top().second] ,hprio.top().second);
            bprio.pop();
            hprio.pop();
        }

        int maxH = 0, minH = INT_MAX;

        for(int currH : h) {
            maxH = max(currH, maxH);
            minH = min(currH, minH);
        }

        if(maxH - minH > x) {
            cout << "NO\n";
        }else {
            cout << "YES\n";
            for(int i = 0; i < n; i++) {
                cout << bindex[i]+1;
                if(i == n-1) cout << '\n';
                else cout << ' ';
            }
        }
    }
}