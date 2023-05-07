#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    vector<int> p(n+1);
    for(int i = 1; i <= n; i++) cin >> p[i];

    int curr = 1, next = p[curr];
    set<int> cycle;

    while(k > 0) {
        curr = next;
        next = p[curr];
        k--;
        if(cycle.count(curr) == 0) cycle.insert(curr);
        else break;
    }

    k = k%cycle.size();

    while(k > 0) {
        curr = next;
        next = p[curr];
        k--;
    }

    cout << curr << '\n';
    return 0;
}