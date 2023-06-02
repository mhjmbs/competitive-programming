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

        vector<ll> a(n);
        for(ll &x : a) cin >> x;
        sort(a.begin(), a.end());

        map<ll,ll> occur;

        int dolls = 0;

        for(ll x : a) {
            occur[x]++;
            if(occur.count(x-1) == 1) {
                occur[x-1]--;
                if(occur[x-1] == 0) occur.erase(x-1);
            }else {
                dolls++;
            }
        }

        cout << dolls << '\n';
    }
}