#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> x(n);
    for(int &xi : x) cin >> xi;

    map<int,vector<int>> occur;
    for(int i = 0; i < n; i++) occur[x[i]].push_back(i+1);

    set<int> indexes;
    vector<int> ans(n, 0);

    for(auto curr : occur) {
        for(int index : curr.second) {
            auto it = indexes.lower_bound(index);
            if(it != indexes.begin()) it--;
            if(it != indexes.end() && *it < index) ans[index-1] = *it;
        }

        for(int index : curr.second) indexes.insert(index);
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i];
        if(i != n-1) cout << ' ';
        else cout << '\n';
    }
}