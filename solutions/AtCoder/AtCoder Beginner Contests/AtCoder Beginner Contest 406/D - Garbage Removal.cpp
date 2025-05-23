#include "bits/stdc++.h"

using namespace std;

using ll = long long;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int h, w, n;
    cin >> h >> w >> n;
    
    vector<set<int>> row(h+1), col(w+1);
    
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        row[x].insert(y);
        col[y].insert(x);
    }
    
    int q;
    cin >> q;
    
    while(q--) {
        int dim, i;
        cin >> dim >> i;
        
        vector<set<int>>& ths = (dim == 1) ? row : col;
        vector<set<int>>& oth = (dim == 1) ? col : row;
        
        cout << ths[i].size() << '\n';
        
        for(int curr : ths[i]) {
            oth[curr].erase(i);
        }
        ths[i].clear();
    }
    
}