#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;

vector<int> rep, sz;
int cc, max_sz = 1;
 
int f(int a) {
    if(rep[a] == a) return a;
    return rep[a] = f(rep[a]);
}
 
void u(int a, int b) {
    a = f(a);
    b = f(b);
    if(a == b) return;
    if(a > b) swap(a,b);
    rep[a] = b;
    sz[b] += sz[a];
    cc--;
    max_sz = max(max_sz, sz[b]);
}
 
int main() {
    fastio;

    int n, m;
    cin >> n >> m;
 
    cc = n;
    rep.resize(n+1);
    sz.resize(n+1, 1);
 
    for(int i = 1; i <= n; i++) rep[i] = i, sz[i] = 1;
    
    priority_queue<tiii, vector<tiii>, greater<tiii>> prioq;
    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        u(a,b);
        cout << cc << ' ' << max_sz << '\n';
    }
}