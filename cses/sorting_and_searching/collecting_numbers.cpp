#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> a(n);
    for(int &x : a) cin >> x;
    set<int> s;

    int ans = 0;

    for(int x : a) {
        auto it = s.find(x-1);
        if(it != s.end()) {
            s.erase(it);
            ans--;
        }
        ans++;
        s.insert(x);
    }

    cout << s.size() << '\n';
}