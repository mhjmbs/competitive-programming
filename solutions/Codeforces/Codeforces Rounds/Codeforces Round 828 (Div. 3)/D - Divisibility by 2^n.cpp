#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int a[n];

        for(int& ai : a) {
            cin >> ai;
        }

        int factors = 0;

        for(int ai : a) {
            while(ai % 2 == 0) {
                ai /= 2;
                factors++;
            }
        }

        vector<int> possibleReduc(32, 0);

        for(int i = 1; i < n+1; i++) {
            int tmpi = i, currReduc = 0;
            
            while(tmpi%2 == 0) {
                currReduc++;
                tmpi /=2;
            }

            possibleReduc[currReduc]++;
        }

        int maxReduc = 31, ans = 0;

        while(maxReduc > 0) {
            if(factors >= n) break;

            if(possibleReduc[maxReduc] == 0) {
                maxReduc--;
            }else {
                factors += maxReduc;
                possibleReduc[maxReduc]--;
                ans++;
            }
        }

        if(factors >= n) {
            cout << ans << '\n';
        }else {
            cout << -1 << '\n';
        }
    }
}