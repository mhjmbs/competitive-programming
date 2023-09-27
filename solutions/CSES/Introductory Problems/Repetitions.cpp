#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    string n;
    cin >> n;

    int curr = 0,ans = 0;
    char last = '0';

    for(char c : n) {
        if(c == last) curr++;
        else curr = 1;
        ans = max(ans, curr);
        last = c;
    }

    cout << ans << '\n';
}