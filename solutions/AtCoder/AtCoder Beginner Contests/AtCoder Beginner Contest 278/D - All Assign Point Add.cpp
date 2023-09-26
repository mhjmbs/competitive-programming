#include "bits/stdc++.h"

using namespace std;
using pii = pair<int,int>;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<ll> a(n+1);
    map<int, ll> sc;
    ll gv;
    bool wow = false;

    for(int i = 1; i <= n; i++) cin >> a[i];

    int q;
    cin >> q;

    for(int i = 0, tq; i < q; i++) {
        cin >> tq;

        if(tq == 1) {
            wow = true;
            cin >> gv;
            sc.clear();
        }else if(tq == 2) {
            int iq, xq;
            cin >> iq >> xq;
            if(wow) {
                if(sc.find(iq) == sc.end()) sc[iq] = gv + xq; 
                else sc[iq] += xq;
            }
            else a[iq] += xq;
        }else {
            int iq;
            cin >> iq;
            if(wow) {
                if(sc.find(iq) == sc.end()) cout << gv << '\n';
                else cout << sc[iq] << '\n';
            }else {
                cout << a[iq] << '\n';
            }
        }
    }
}