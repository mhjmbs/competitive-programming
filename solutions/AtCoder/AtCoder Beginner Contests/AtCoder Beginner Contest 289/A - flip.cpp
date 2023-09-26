#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '0') cout << 1;
        else cout << 0;
    }
    cout << '\n';
}