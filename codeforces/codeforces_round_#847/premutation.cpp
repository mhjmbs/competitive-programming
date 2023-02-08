#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<vector<int>> p(n, vector<int>(n-1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n-1; j++) {
                cin >> p[i][j];
            }
        }

        vector<int> s0 = p[0], s1 = p[1], s2 = p[2], original;
        s0.push_back(-1);
        s1.push_back(-1);
        s2.push_back(-1);
        int i0 = 0, i1 = 0, i2 = 0;

        while(i0 < n-1 || i1 < n-1 || i2 < n-1) {
            if(s0[i0] == s1[i1] && s1[i1] == s2[i2]) {
                original.push_back(s0[i0]);
                i0++; i1++; i2++;
            }else if(s0[i0] == s1[i1] && s1[i1] != s2[i2]) {
                original.push_back(s0[i0]);
                i0++; i1++;
            }else if(s0[i0] != s1[i1] && s1[i1] == s2[i2]) {
                original.push_back(s1[i1]);
                i1++; i2++;
            }else if(s0[i0] == s2[i2] && s0[i0] != s1[i1]) {
                original.push_back(s0[i0]);
                i0++; i2++;
            }
        }

        for(int i = 0; i < original.size(); i++) {
            cout << original[i];
            if(i != original.size()-1) cout << ' ';
            else cout << '\n';
        }
    }
}