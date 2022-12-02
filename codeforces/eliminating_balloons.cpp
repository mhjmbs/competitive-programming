#include "bits/stdc++.h"
     
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);

    int n, ans = 0;
    cin >> n;
 
    vector<int> balloonFreq(1000002, 0);
 
    for(int i = 0, currB; i < n; i++) {
        cin >> currB;
        
        balloonFreq[currB]++;
        if(balloonFreq[currB+1] > 0) {
            balloonFreq[currB+1]--;
        }else {
            ans++;
        }
    }
 
    cout << ans << '\n';
}
