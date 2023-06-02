#include "bits/stdc++.h"

using namespace std;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    set<char> Yes = {'Y', 'e', 's'};
    map<char, char> last;
    last['Y'] = 's';
    last['e'] = 'Y';
    last['s'] = 'e';

    while(t--) {
        string s;
        cin >> s;

        bool correct = true;
        for(int i = 0; i < s.size(); i++) {
            if(Yes.count(s[i]) == 0) {
                correct = false;
                break;
            }

            if(i == 0) continue;

            if(s[i-1] != last[s[i]]) {
                correct = false;
                break;
            }
        }

        if(correct) cout << "YES\n";
        else cout << "NO\n";
    }

}