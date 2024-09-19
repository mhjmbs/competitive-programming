#pragma once

#include <bits/stdc++.h>

using namespace std;

namespace cp {

using bs = bitset<64>;
int gauss(vector<bs> A, int m, bs& x) {
    int n = A.size();
    vector<int> pivot(m, -1);
    for(int i = 0, j = 0; i < n && j < m; j++) {
        if(!(A[i][j])) {
            for(int k = i+1; k < n; k++) {
                if(A[k][j]) {
                    swap(A[i],A[k]);
                    break;
                }
            }
        }

        if(!A[i][j]) continue;
        pivot[j] = i;

        for(int k = i+1; k < n; k++) {
            if(i != k && A[k][j]) A[k] ^= A[i];
        }

        i++;
    }

    for(int i = 0; i < m; i++) x[i] = 0;

    for(int j = m-1; j >= 0; j--) {
        if(pivot[j] == -1) continue;
        int sum = 0;
        for(int k = m-1; j < k; k--) sum ^= A[pivot[j]][k]*x[k];
        sum ^= A[pivot[j]][m];
        x[j] = sum;
    }

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < m; j++) {
            sum ^= A[i][j]*x[j];
        }
        if(sum != A[i][m]) return 0;
    }

    return *min_element(pivot.begin(), pivot.end()) == -1 ? 2 : 1;
}

}