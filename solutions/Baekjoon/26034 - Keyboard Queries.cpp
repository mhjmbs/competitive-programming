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

struct DSU {
    vector<int> rep, height;

    DSU(int n) : rep(n), height(n) {
        iota(rep.begin(), rep.end(), 0);
    }

    int find(int u) {
        return (rep[u] == u) ? u : rep[u] = find(rep[u]); 
    }

    bool merge(int u, int v) {
        u = find(u);
        v = find(v);

        if(u == v) return false;

        if(height[u] < height[v]) swap(u,v);
        rep[v] = u;
        height[u] = max(height[u], height[v]+1);

        return true;
    }
};

int n, q;

void update(int l1, int l2, int p, vector<DSU>& dsus) {
    if(p < 0) return;
    if(dsus[p].merge(l1, l2)) {
        update(l1, l2, p-1, dsus);
        update(l1+(1 << (p-1)), l2+(1 << (p-1)), p-1, dsus);
    }
}

bool query(int l1, int l2, int p, vector<DSU>& dsus) {
    if(p < 0) return false;
    if(dsus[p].find(l1) == dsus[p].find(l2)) return true;
    bool result = query(l1, l2, p-1, dsus) && query(l1+(1<<p-1), l2+(1<<p-1), p-1, dsus);
    if(result) dsus[p].merge(l1, l2);
    return result;
}

int inv(int l, int i) {
    return 2*n - l - (1<<i) + 2;
}

int main() {
    fastio;

    cin >> n >> q;

    vector<DSU> dsus(__lg(2*n+1)+1, DSU(2*n+1));

    for(int i = 1; i <= n; i++) dsus[0].merge(i, inv(i,0));

    while(q--) {
        int tq;
        cin >> tq;

        if(tq == 1) {
            int l, r;
            cin >> l >> r;

            int length = (r-l+1)/2;
            for(int i = 0; i < 32; i++) {
                if(length & (1 << i)) {
                    update(l, inv(r-(1<<i)+1,i), i, dsus);
                    l += (1 << i);
                    r -= (1 << i);
                }
            }
        }else {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2; 
           
            if(r2 - l2 != r1 - l1) {
                cout << "Not equal\n";
            }else {
                bool equal = true;
                int length = r2-l2+1;
                for(int i = 0; i < 32; i++) {
                    if(length & (1 << i)) {
                        equal = equal && query(l1, l2, i, dsus);
                        l1 += (1 << i);
                        l2 += (1 << i);
                    }
                }
                cout << (equal ? "Equal\n" : "Unknown\n");
            }
        }
    }
}