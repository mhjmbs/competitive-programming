#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

int main(){
    fastio;
 
    int n;
    cin >> n;
 
    vector<int> t(2*n);
    map<int, int> ind_s, ind;
 
    for(int i = 0; i < 2*n; i++) {
        cin >> t[i];
        ind[t[i]] = i;
    }
    vector<int> t_s = t;
    sort(t_s.begin(), t_s.end());
    for(int i = 0; i < 2*n; i++) {
        ind_s[t_s[i]] = i;
    }
 
    int moves = 0;
 
    for(int i = 0; i < 2*n; i+=2) {
        if(t[i+1] != t_s[2*n-1 - ind_s[t[i]]]) {
            moves++;
            int temp1 = t[i+1];
            t[i+1] = t_s[2*n-1 - ind_s[t[i]]];
            t[ind[t_s[2*n-1 - ind_s[t[i]]]]] = temp1;
 
            int temp2 = ind[t[i+1]];
            ind[t[i+1]] = i+1;
            ind[temp1] = temp2;
        }
    }
 
    cout << moves << '\n';
    return 0;
}