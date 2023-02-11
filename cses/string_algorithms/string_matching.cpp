#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

vector<int> z_function(string s) {
    vector<int> z(s.size(), 0);

    for(int i = 1, l = 0, r = 0; i < s.size(); i++) {
        if(i <= r) z[i] = min(z[i-l], r-i+1);
        while(i+z[i] < s.size() && s[i+z[i]] == s[z[i]]) z[i]++;
        if(i+z[i]-1 > r) l = i, r = i+z[i]-1;
    }

    return z;
}

int main() {
    fastio;

    string s, m;
    cin >> s >> m;

    vector<int> z = z_function(m + "#" + s);

    int ans = 0;

    for(int i = m.size()+1; i < z.size(); i++)
        if(z[i] == m.size())
            ans++;

    cout << ans << '\n';
}