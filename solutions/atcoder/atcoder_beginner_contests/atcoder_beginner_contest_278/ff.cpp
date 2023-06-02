#include "bits/stdc++.h"

using namespace std;
using pii = pair<int,int>;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    set<pii> f;

    for(int i = 0, t, a, b; i < q; i++) {
        cin >> t >> a >> b;
        if(t == 1) {
            f.emplace(a,b);
        }else if(t == 2) {
            f.erase(make_pair(a,b));
        }else {
            if(f.count(make_pair(a,b)) && f.count(make_pair(b,a))) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}