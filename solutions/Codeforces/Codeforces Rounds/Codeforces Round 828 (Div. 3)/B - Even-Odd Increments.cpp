#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--) {
        int n, q, even = 0, odd = 0;
        cin >> n >> q;
        ll sum = 0;
        for(int i = 0, currNum; i < n; i++) {
            cin >> currNum;
            sum += currNum;
            if(currNum % 2) odd++;
            else even++;
        }

        for(int i = 0, type, xj; i < q; i++) {
            cin >> type >> xj;

            if(type) {
                if(xj % 2) {
                    sum += odd*xj;
                    even += odd;
                    odd = 0;
                }else {
                    sum += odd*xj;
                }
            }else {
                if(xj % 2) {
                    sum += even*xj;
                    odd += even;
                    even = 0;
                }else {
                    sum += even*xj;
                }
            } 

            cout << sum << '\n';
        }
    }
}