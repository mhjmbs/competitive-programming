#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n;
    cin >> n;

    auto comp = [](pii a, pii b) {
        return a.first < b.first;
    };

    vector<pii> a(n);
    for(pii &ai : a) cin >> ai.first >> ai.second;
    sort(a.begin(), a.end(), comp);

    ll currTime = 0, score = 0;

    for(pii &ai : a) {
        currTime += ai.first;
        score += ai.second - currTime;
    }

    cout << score << '\n';
}