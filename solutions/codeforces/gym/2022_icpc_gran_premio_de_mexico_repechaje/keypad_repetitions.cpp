#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

void transform(string &s) {
    for(char &c : s) {
        if(c <= 'c') c = '2';
        else if(c <= 'f') c = '3';
        else if(c <= 'i') c = '4';
        else if(c <= 'l') c = '5';
        else if(c <= 'o') c = '6';
        else if(c <= 's') c = '7';
        else if(c <= 'v') c = '8';
        else c = '9';
    }
}

int main() {
    fastio;

    int n, q;
    cin >> n >> q;

    map<string, int> yay;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        transform(s);
        yay[s]++;
    }

    for(int i = 0; i < q; i++) {
        string s;
        cin >> s;

        if(yay.find(s) != yay.end()) {
            cout << yay[s] << '\n';
        }else {
            cout << 0 << '\n';
        }
    }
}