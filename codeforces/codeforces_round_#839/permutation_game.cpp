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

        vector<int> p(n+1);
        for(int i = 1; i <= n; i++) cin >> p[i];

        int a = 0, b = 0, c = 0;

        for(int i = 1; i <= n; i++) {
            if(p[i] != i && p[i] != n-i+1) c++;
            else if(p[i] != i) a++;
            else if(p[i] != n-i+1) b++;
        }

        int win = 0;

        if(a+c <= b) win = 1;
        if(b+c < a) win = 2;
        
        if(win == 0) cout << "Tie\n";
        else if(win == 1) cout << "First\n";
        else cout << "Second\n";
    }
}