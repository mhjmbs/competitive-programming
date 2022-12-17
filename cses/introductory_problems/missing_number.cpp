#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    bool in[n+1] = {false};

    for(int i = 0, inp; i < n-1; i++) {
        cin >> inp;
        in[inp] = true;
    }

    for(int i = 1; i <= n; i++) {
        if(in[i] == false) {
            cout << i << '\n';
            break;
        }
    }
}