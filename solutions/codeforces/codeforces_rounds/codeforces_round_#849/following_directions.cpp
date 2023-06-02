#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>> t;

    while(t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        pii coord = {0,0};

        bool yes = false;

        for(char c : s) {
            if(c == 'U') coord.second++;
            else if(c == 'R') coord.first++;
            else if(c == 'D') coord.second--;
            else coord.first--;

            if(coord == make_pair(1,1)) yes = true;
        }

        if(yes) cout << "YES\n";
        else cout << "NO\n";
    }
}