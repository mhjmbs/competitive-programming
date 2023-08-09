#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    
    char ans = 'S';

    for(int i = 0, inp; i < 8; i++) {
        cin >> inp;
        if(inp == 9) {
            ans = 'F';
        }
    }

    cout << ans << '\n';
}
