#include "bits/stdc++.h"

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string ticket;
        cin >> ticket;

        int first3 = 0, last3 = 0;

        for(int i = 0; i < 3; i++) {
            first3 += ticket[i] - '0';
        }

        for(int i = 3; i < 6; i++) {
            last3 += ticket[i] - '0';
        }

        if(first3 == last3) cout << "YES\n";
        else cout << "NO\n";
    }
}