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
using ppi = pair<pii,pii>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

struct bm_t {
    int N, M, T;
    vector<vector<int>> adj;
    vector<int> match, seen;
    bm_t(int a, int b) : N(a), M(a+b), T(0), adj(M),
    match(M, -1), seen(M, -1) {}
    void add_edge(int a, int b) {adj[a].push_back(b + N); }
    bool dfs(int cur) {
        if(seen[cur] == T) return false;
        seen[cur] = T;
        for(int nxt : adj[cur]) if(match[nxt] == -1) {
            match[nxt] = cur, match[cur] = nxt;
            return true;
        }
        for(int nxt : adj[cur]) if(dfs(match[nxt])) {
            match[nxt] = cur, match[cur] = nxt;
            return true;
        }
        return false;
    }
    int solve() {
        int res = 0;
        for(int cur = 1; cur;) {
            cur = 0; T++;
            for(int i = 0; i < N; i++) if(match[i] == -1)
                cur += dfs(i);
            res += cur;
        }
        return res;
    }
};

bool intersect(ppi hor, ppi ver) {
    return hor.first.first <= ver.first.first && hor.second.first >= ver.first.first && ver.first.second <= hor.first.second && ver.second.second >= hor.first.second;
}

int main() {
    fastio;

    int n;
    cin >> n;

    vector<ppi> hor, ver;
    int count = 0;
    map<ppi, int> id;

    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2) {
            if(y1 <= y2) ver.emplace_back(make_pair(x1,y1),make_pair(x2,y2));
            else ver.emplace_back(make_pair(x2,y2),make_pair(x1,y1));
            id[ver.back()] = count++;
        }else {
            if(x1 <= x2) hor.emplace_back(make_pair(x1,y1),make_pair(x2,y2));
            else hor.emplace_back(make_pair(x2,y2),make_pair(x1,y1));
            id[hor.back()] = count++;
        }
    }

    bm_t bm(n, n*n);

    for(ppi l1 : hor) {
        for(ppi l2 : ver) {
            if(intersect(l1,l2)) {
                bm.add_edge(id[l1], id[l2]);
                bm.add_edge(id[l2], id[l1]);
            }
        }
    }

    cout << n-bm.solve()/2 << '\n';

}