#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

vector<int> z;
int n, m;

void z_algo(string s){
    for(int i=1, l=0, r=0; i<n; i++){
        if(i<=r){
            z[i]=min(r-i+1, z[i-l]);
        }
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
            z[i]++;
        }
        if(i+z[i]-1>r){
            l=i, r=i+z[i]-1;
        }
    }
}

int main() {
    fastio;

    cin >> n >> m;

    string s;
    cin >> s;

    z.resize(n);
    z_algo(s);

    int p = 1;

    for(int i = 1; i < n; i++) {
        if(z[i] == n-i) {
            p = i;
            break;
        }
    }

    int i = n%p;
    while(m--) {
        cout << s[i];
        i = (i+1) % p;
    }
    cout << '\n';
}