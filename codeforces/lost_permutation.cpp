#include "bits/stdc++.h"

using namespace std;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--) {
        int m, s;
        cin >> m >> s;

        vector<bool> found(1000, false);
        int lastFound = 0;
        for(int i = 0, bi; i < m; i++) {
            cin >> bi;
            lastFound = max(lastFound, bi);
            found[bi] = true;
        }

        int currs = 0, currnum = 1;

        while(currs < s) {
            if(!found[currnum]) {
                currs += currnum;
                found[currnum] = true;
                lastFound = max(lastFound, currnum);
            }
            currnum++;
        }

        if(currs > s) {
            cout << "NO\n";
            continue;
        }

        bool correct = true;
        for(int i = 1; i <= lastFound; i++) {
            if(!found[i]) correct = false;
        }

        if(correct) cout << "YES\n";
        else cout << "NO\n";
    }
}