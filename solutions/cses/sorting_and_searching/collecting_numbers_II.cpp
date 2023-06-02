#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    vector<int> pos(n+1, INT_MAX), x(n+1);
    for(int i = 1, inp; i <= n; i++) {
        cin >> inp;
        pos[inp] = i;
        x[i] = inp;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(pos[x[i]] < pos[x[i]-1]) ans++;
    }

    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        if(a > b) swap(a,b);

        if(x[a]+1 <= n && a < pos[x[a]+1] && !(b <= pos[x[a]+1])) ans++;
        if(x[b]-1 != 0 && pos[x[b]-1] < b && !(pos[x[b]-1] < a)) ans++;

        if(x[a]-1 != 0 && !(pos[x[a]-1] < a) && pos[x[a]-1] <= b) ans--;
        if(x[b]+1 <= n && !(b < pos[x[b]+1]) && a < pos[x[b]+1]) ans--;

        swap(pos[x[a]],pos[x[b]]);
        swap(x[a],x[b]);

        cout << ans << '\n';
    }
}