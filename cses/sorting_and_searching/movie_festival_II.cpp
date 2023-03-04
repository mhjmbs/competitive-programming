#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    vector<pii> movies;
    for(int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        movies.emplace_back(a,b);
    }

    auto earliest_end = [](pii a, pii b) {
        if(a.second < b.second) return true;
        else if(a.second > b.second) return false;
        else return a.first < b.first;
    };
    sort(movies.begin(), movies.end(), earliest_end);

    multiset<ll> members;
    for(int i = 0; i < k; i++) members.insert(0);

    int ans = 0;

    for(pii movie : movies) {
        auto it = members.upper_bound(movie.first);
        if(it != members.begin()) it--;

        if(it != members.end() && *it <= movie.first) {
            members.erase(it);
            members.insert(movie.second);
            ans++;
        }
    }

    cout << ans << '\n';
}