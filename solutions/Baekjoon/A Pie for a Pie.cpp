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
using tiiii = tuple<int,int,int,int>;
using tiiiii = tuple<int,int,int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;



int main() {
    fastio;

    int n, d;
    cin >> n >> d;

    vector<int> ans(2*n, -1);

    multiset<array<int,4>> br, e;

    queue<array<int,5>> q;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if(y == 0) q.push({x,y,i,1,1});
        else br.insert({y,x,i,1});
    }

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if(x == 0) q.push({x,y,i+n,2,1});
        else e.insert({x,y,i+n,2});
    }

    while(!q.empty()) {
        auto [x,y,i,p,dist] = q.front();
        q.pop();

        ans[i] = dist;

        if(p == 1) {
            auto it = e.upper_bound({x-d,-1,-1,-1});

            while(it != e.end() && (*it)[0] <= x) {
                auto [nx, ny, ni, np] = *it;
                q.push({nx, ny, ni, np, dist+1});
                auto cp = it;
                it++;
                e.erase(cp);
            }
        }else {
            auto it = br.upper_bound({y-d,-1,-1,-1});

            while(it != br.end() && (*it)[0] <= y) {
                auto [ny, nx, ni, np] = *it;
                q.push({nx, ny, ni, np, dist+1});
                auto cp = it;
                it++;
                br.erase(cp);
            }
        }
    }

    for(int i = 0; i < n; i++) cout << ans[i] << '\n';
}