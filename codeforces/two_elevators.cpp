    #include "bits/stdc++.h"
    
    using namespace std;
    
    int main() {
        ios::sync_with_stdio(0);

        int t;
        cin >> t;
    
        for(int i = 0,a,b,c; i < t; i++) {
            cin >> a >> b >> c;
    
            if(a-1 < abs(b-c) + c-1)
                cout << 1 << '\n';
            else if(a-1 > abs(abs(b-c)+ c-1))
                cout << 2 << '\n';
            else    
                cout << 3 << '\n';
        }
    }