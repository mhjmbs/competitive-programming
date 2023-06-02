#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--) {
        int s;
        cin >> s;
        
        vector<int> digits(10, -1);
        
        int currD = 9;
        while(s > 0) {
            digits[currD] = min(currD, s);
            s -= currD;
            currD--;
        }

        for(int d : digits) {
            if(d != -1) cout << d;
        }
        cout << '\n';
    }
}
