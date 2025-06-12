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
    vector<int> parent;
    vector<int> height;

    Dsu(int n) {
        height.resize(n, 0);
        parent.resize(n, -1);
    }

    void add() {
        height.push_back(0);
        parent.push_back(-1);
    }

    int find(int u) {
        return parent[u] == -1 ? u : parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);

        if(u != v) {
            if(height[u] < height[v]) swap(u, v);

            parent[v] = u;
            height[u] = max(height[u], height[v]+1);
        }
    }
};

struct Point {
    int x;
    int y;
};

int d(Point a, Point b) {
    auto [x1, y1] = a;
    auto [x2, y2] = b;
    return abs(x1-x2) + abs(y1-y2);
}

int main() {
    fastio;

    int n, q;
    cin >> n >> q;

    vector<Point> p(n);
    for(auto& [x,y] : p) cin >> x >> y;

    int k = INT_MAX;
    vector<pii> best(n, {INT_MAX, INT_MAX});

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            k = min(k, d(p[i],p[j]));
            best[i] = min(best[i], {d(p[i],p[j]), j});
        }
    }

    Dsu dsu(n);

    while(q--) {
        int type;
        cin >> type;

        switch(type) {
            case 1: {
                int x, y;
                cin >> x >> y;
                p.push_back({x,y});
                dsu.add();
                best.push_back({INT_MAX, INT_MAX});
                n++;
                for(int v = 0; v < n-1; v++) {
                    best[n-1] = min(best[n-1], {d(p[n-1],p[v]), v});
                    best[v] = min(best[v], {d(p[n-1],p[v]), n-1});
                }
                k = min(k, best[n-1].first);
                break;
            }
            
            case 2: {
                if(k == INT_MAX) {
                    cout << -1 << '\n';
                }else {
                    cout << k << '\n';

                    for(int u = 0; u < n; u++) {
                        while(best[u].first == k) {
                            dsu.merge(u, best[u].second);
                            best[u] = {INT_MAX, INT_MAX};
                            for(int v = 0; v < n; v++) {
                                if(dsu.find(u) == dsu.find(v)) continue;
                                best[u] = min(best[u], {d(p[u],p[v]), v});
                            }
                        }
                    }

                    for(int u = 0; u < n; u++) {
                        if(best[u].first != INT_MAX && dsu.find(u) == dsu.find(best[u].second)) {
                            best[u] = {INT_MAX, INT_MAX};
                            for(int v = 0; v < n; v++) {
                                if(dsu.find(u) == dsu.find(v)) continue;
                                best[u] = min(best[u], {d(p[u],p[v]), v});
                            }
                        }
                    }

                    int nk = INT_MAX;
                    for(auto [d,v] : best) nk = min(nk, d);
                    k = nk;
                }
                break;
            }

            case 3: {
                int u, v;
                cin >> u >> v;
                u--, v--;
                cout << (dsu.find(u) == dsu.find(v) ? "Yes\n" : "No\n");
                break;
            }
        }
    }
}