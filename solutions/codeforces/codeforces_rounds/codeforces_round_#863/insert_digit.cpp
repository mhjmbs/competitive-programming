#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        char d;
        cin >> d;

        string s;
        cin >> s;

        bool printed = false;

        for(char c : s) {
            if(d > c && !printed) {
                cout << d;
                printed = true;
            }
            cout << c;
        }
        if(!printed) cout << d;
        cout << '\n';
    }
}