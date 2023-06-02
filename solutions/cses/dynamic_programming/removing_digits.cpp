#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n, moves = 0;

    cin >> n;

    while(n != 0) {
        int maxd = 0, tmpn = n;
        while(tmpn != 0) {
            maxd = max(maxd, tmpn%10);
            tmpn /= 10;
        }
        
        n -= maxd;
        moves++;
    }

    cout << moves << '\n';
}