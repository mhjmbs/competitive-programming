#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using tiii = tuple<int,int,int>;

int main() {
    fastio;

    int n;
    cin >> n;

    vector<tiii> customers(n);
    for(int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        customers[i] = {a,b,i};
    }

    sort(customers.begin(),customers.end());

    multiset<pii> rooms;
    int next_room = 1;

    vector<int> ans(n);

    for(tiii c : customers) {
        int room = next_room;
        auto it = rooms.lower_bound(make_pair(get<0>(c), INT_MIN));
        if(it != rooms.begin()) it--;
        if(it != rooms.end() && it->first < get<0>(c)) {
            room = it->second;
            rooms.erase(it);
        }else {
            next_room++;
        }
        rooms.emplace(get<1>(c), room);

        ans[get<2>(c)] = room;
    }

    cout << rooms.size() << '\n';

    for(int i = 0; i < n; i++) {
        cout << ans[i];
        if(i != n-1) cout << ' ';
        else cout << '\n';
    }
}