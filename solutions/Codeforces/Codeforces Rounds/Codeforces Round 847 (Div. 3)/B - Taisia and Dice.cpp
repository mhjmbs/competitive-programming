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
        int n, s, r;
        cin >> n >> s >> r;

        int maxai = s-r;

        vector<int> dice(n-1, 0);

        int i = 0;
        while(r > 0) {
            if(i == dice.size()) {
                i = 0;
            }else {
                dice[i]++;
                r--;
                i++;
            }
        }

        cout << maxai << ' ';

        for(int i = 0; i < dice.size(); i++) {
            cout << dice[i];
            if(i != dice.size()-1) cout << ' ';
            else cout << '\n';
        }
    }
}