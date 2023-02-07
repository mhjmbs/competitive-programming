#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

vector<int> rep, sz;

int find(int a) {
    if(rep[a] == a) return a;
    return rep[a] = find(rep[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    rep[b] = rep[a];
    sz[a] += sz[b];
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    rep.resize(n+1);
    sz.resize(n+1, 1);
    for(int i = 1; i <= n; i++) rep[i] = i;

    for(int i = 0, ki, first; i < m; i++) {
        cin >> ki;
        if(ki > 0) cin >> first;
        for(int j = 1, inp; j < ki; j++) {
            cin >> inp;
            merge(first, inp);
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << sz[find(i)];
        if(i == n) cout << '\n';
        else cout << ' ';
    }
}