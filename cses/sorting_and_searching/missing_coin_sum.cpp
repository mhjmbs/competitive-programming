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
    sort(a.begin(), a.end());

    ll currSum = 0;
    for(int x : a) {
        if(x <= currSum + 1) currSum += x;
        else break;
    }
    cout << currSum+1 << '\n';
}