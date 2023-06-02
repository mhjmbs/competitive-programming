#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    bool possible = n*(n+1)/2 % 2 == 0;

    set<int> set1, set2;

    if(possible) {

        cout << "YES\n";

        if(n % 2 == 0) {
            for(int i = 1; i <= n; i += 4) {
                set1.insert({i,i+3});
                set2.insert({i+1,i+2});
            }
        }else {
            set1.insert({1,2});
            set2.insert(3);
            for(int i = 4; i <= n; i += 4) {
                set1.insert({i,i+3});
                set2.insert({i+1,i+2});
            }
        }

        cout << set1.size() << '\n';
        for(auto it = set1.begin(); it != set1.end(); it++) {
            cout << *it;
            if(*it == *set1.rbegin()) cout << '\n';
            else cout << ' ';
        }

        cout << set2.size() << '\n';
        for(auto it = set2.begin(); it != set2.end(); it++) {
            cout << *it;
            if(*it == *set2.rbegin()) cout << '\n';
            else cout << ' ';
        }

    }else {
        cout << "NO\n";
    }    
}