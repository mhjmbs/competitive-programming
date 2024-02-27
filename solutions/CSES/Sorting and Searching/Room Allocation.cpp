#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;



int main() {
    fastio;

    int n;
    cin >> n;

    multiset<pii> rooms;
    vector<tiii> intervals(n);

    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        intervals[i] = {l,r, i};
    }

    sort(intervals.begin(), intervals.end());

    int nextRoom = 1;
    vector<int> ans(n);

    for(auto [l,r,i] : intervals) {
        int room;
        if(rooms.empty() || l <= rooms.begin()->first) {
            room = nextRoom++;
        }else {
            room = rooms.begin()->second;
            rooms.erase(rooms.begin());
        }
        rooms.emplace(r, room);
        ans[i] = room;
    }

    cout << nextRoom-1 << '\n';

    for(int x : ans) cout << x << ' ';
    cout << '\n';
}