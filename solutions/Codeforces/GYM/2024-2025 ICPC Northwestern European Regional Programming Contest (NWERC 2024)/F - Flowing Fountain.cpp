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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


struct Dsu {
    vector<int> p, h, curr;
    
    Dsu(int n) : h(n), p(n, -1), curr(n) {
        iota(curr.begin(), curr.end(), 0);
    }
    
    int find(int u) {
        return p[u] == -1 ? u : p[u] = find(p[u]);
    }

    int get_curr(int u) {
        return curr[find(u)];
    }
    
    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        
        if(u != v) {
            if(h[u] < h[v]) swap(u,v);

            p[v] = u;
            h[u] = max(h[u], h[v]+1);
            curr[u] = max(curr[u], curr[v]);
        }
    }
};

int n, q;
vector<ll> c, cnt, nxt;
Dsu dsu(0);

void put(int l, int x) {
    l = dsu.get_curr(l);
    if(cnt[l] + x < c[l]) {
        cnt[l] += x;
    }else {
        x -= c[l] - cnt[l];
        cnt[l] = c[l];
        dsu.merge(l, nxt[l]);
        put(l, x);
    }
}

int main() {
    fastio;

    cin >> n >> q;

    c.resize(n+1);
    cnt.resize(n+1);
    nxt.resize(n+1);

    for(int i = 0; i < n; i++) cin >> c[i];
    c[n] = LONG_LONG_MAX;

    priority_queue<pll, vector<pll>, greater<pll>> prioq;

    for(int i = 0; i <= n; i++) {
        while(!prioq.empty() && prioq.top().first < c[i]) {
            auto [cj, j] = prioq.top();
            nxt[j] = i;
            prioq.pop();
        }
        prioq.emplace(c[i], i);
    }
    nxt[n] = n;

    dsu = Dsu(n+1);
    
    while(q--) {
        char t;
        cin >> t;
        
        if(t == '+') {
            int l, x;
            cin >> l >> x;
            l--;
            put(l,x);
        }else {
            int l;
            cin >> l;
            l--;
            cout << cnt[l] << '\n';
        }

        // cout << "-----\n";
        // for(int i = 0; i < n; i++) cout << cnt[i] << ' ';
        // cout << '\n';
        // for(int i = 0; i < n; i++) cout << dsu.get_curr(i) << ' ';
        // cout << '\n';
        // cout << "-----" << endl;
    }
}