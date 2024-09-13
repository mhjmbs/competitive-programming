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

int n, t;

ll add(ll a, ll b) {
    a += b;
    if(a >= t) a -= t;
    return a;
}

ll sub(ll a, ll b) {
    a -= b;
    if(a < 0) a += t;
    return a;
}

int main() {
    fastio;

    cin >> n >> t;

    vector<ll> g(n), o(n);
    vector<pll> green(n), red(n);

    for(int i = 0; i < n; i++) cin >> g[i] >> o[i];

    ll tSum = 0;

    for(ll i = 1, sum = 0, ti; i < n; i++) {
        cin >> ti;
        tSum += ti;
        sum = (sum + ti) % t;
        o[i] = add(o[i], sum);
    }

    for(int i = 0; i < n; i++) {
        green[i] = {sub(0, o[i]), sub(g[i], add(o[i],1))};
        red[i] = {add(green[i].second, 1), sub(green[i].first, 1)};
    }

    set<pll> pending;
    for(int i = 0; i < n; i++) pending.emplace(green[i].second, i);

    vector<int> stop(n, -1), partial(n, -1);

    for(int i = 0; i < n; i++) {
        while(true) {
            if(red[i].first <= red[i].second) {
                auto it = pending.lower_bound({red[i].first,LONG_LONG_MIN});
                if(it != pending.end() && it->first <= red[i].second) {
                    stop[it->second] = i;
                    pending.erase(it);
                }else {
                    break;
                }
            }else {
                auto it = pending.lower_bound({red[i].first,LONG_LONG_MIN});
                if(it != pending.end()) {
                    stop[it->second] = i;
                    pending.erase(it);
                }else {
                    it = pending.lower_bound({0,LONG_LONG_MIN});
                    if(it != pending.end() && it->first <= red[i].second) {
                        stop[it->second] = i;
                        pending.erase(it);
                    }else {
                        break;
                    }
                }
            }
        }
    }

    pending.clear();

    for(int i = 0; i < n; i++) {
        while(true) {
            if(red[i].first <= red[i].second) {
                auto it = pending.lower_bound({red[i].first,LONG_LONG_MIN});
                if(it != pending.end() && it->first <= red[i].second) {
                    partial[it->second] = i;
                    pending.erase(it);
                }else {
                    break;
                }
            }else {
                auto it = pending.lower_bound({red[i].first,LONG_LONG_MIN});
                if(it != pending.end()) {
                    partial[it->second] = i;
                    pending.erase(it);
                }else {
                    it = pending.lower_bound({0,LONG_LONG_MIN});
                    if(it != pending.end() && it->first <= red[i].second) {
                        partial[it->second] = i;
                        pending.erase(it);
                    }else {
                        break;
                    }
                }
            }
        }
        pending.emplace(green[i].first, i);
    }

    vector<ll> finish(n, 0);

    for(int i = n-1; i >= 0; i--) {
        if(partial[i] != -1) {
            finish[i] = finish[partial[i]] + sub(green[partial[i]].first,green[i].first);
        }
    }

    ll ans = LONG_LONG_MAX;

    for(int i = 0; i < n; i++) {
        if(stop[i] == -1) {
            ans = 0;
            break;
        }
        ans = min(ans, finish[stop[i]] + sub(green[stop[i]].first,green[i].second));
    }

    cout << ans + tSum << '\n';
}