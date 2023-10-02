#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        string s;
        cin >> s;

        char expected = 'm', next = 'e';
        bool yes = true, m, e, o, w;
        m = e = o = w = false;

        for(char c : s) {
            c = tolower(c);

            if(c == 'm') m = true;
            if(c == 'e') e = true;
            if(c == 'o') o = true;
            if(c == 'w') w = true;

            if(c != expected) {
                if(c == next) {
                    expected = next;
                    if(expected == 'e') next = 'o';
                    else if(expected == 'o') next = 'w';
                    else if(expected == 'w') next = '#';
                }else {
                    yes = false;
                    break;
                }
            }
        }

        if(!(m && e && o && w)) yes = false;

        if(yes) cout << "YES\n";
        else cout << "NO\n";
    }
}