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
using tllll = tuple<ll,ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

struct event{
    int u;
    int type;
    int time;
    int i;
};

int main() {
    fastio;

    int n, m, x1;
    cin >> n >> m >> x1;

    vector<event> events(2*m);
    vector<ll> x(m,0);
    x[0] = x1;

    for(int i = 0; i < 2*m; i+=2) {
        int u, v, s, t;
        cin >> u >> v >> s >> t;
        events[i] = {u,0,s,i/2};
        events[i+1] = {v,1,t,i/2};
    }

    sort(events.begin(), events.end(), [](event a, event b) {
        if(a.time < b.time) return true;
        if(a.time > b.time) return false;
        return a.type > b.type;
    });

    vector<ll> worst(n+1, 0);

    for(auto [u, type, time, i] : events) {
        if(type == 0) {
            x[i] = max(worst[u]-time,x[i]);
        }else {
            worst[u] = max(worst[u],time+x[i]);
        }
    }

    for(int i = 1; i < m; i++) {
        cout << x[i] << ' ';
    }
    cout << '\n';
}