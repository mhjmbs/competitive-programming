#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<int> row(n);

    for(int i = 0; i < n; i++) {
        cin >> row[i];
    }

    ll ans = 0;
    map<int,int> bookFreq;

    for(int l = 0, r = 0; r != n; r++) {
        bookFreq[row[r]]++;

        while(bookFreq.size() > k) {
            bookFreq[row[l]]--;
            if(bookFreq[row[l]] == 0) bookFreq.erase(row[l]);
            l++;
        }

        ans += r-l+1;
    }

    bookFreq.clear();

    for(int l = 0, r = 0; r != n; r++) {
        bookFreq[row[r]]++;

        while(bookFreq.size() > k-1) {
            bookFreq[row[l]]--;
            if(bookFreq[row[l]] == 0) bookFreq.erase(row[l]);
            l++;
        }

        ans -= r-l+1;
    }
    cout << ans << '\n';
}