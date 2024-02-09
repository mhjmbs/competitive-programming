#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
struct FenwickTree {
    int n;
    vector<T> tree;

    FenwickTree(vector<T>& v) : n(v.size()), tree(n, 0) {
        for(int i = 1; i <= n; i++) {
            tree[i] += v[i-1];
            if(i+(i&-i) <= n) tree[i+(i&-i)] += tree[i];
        }
    }

    void sum(int i, T val) {
        while(i <= n) {
            tree[i] += val;
            i += i&-i;
        }
    }

    T query(int r) {
        T ans = 0;
        while(r > 0) {
            ans += tree[r];
            r -= r&-r;
        }
        return ans;
    }
};

int main() {
    fastio;

    int n, q;
    cin >> n >> q;

    vector<ll> x(n);
    for(ll&xi : x) cin >> xi;

    FenwickTree<ll> ft(x);

    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;

        if(t == 1) {
            ft.sum(a, b-x[a-1]);
            x[a-1] = b;
        }else {
            cout << ft.query(b)-ft.query(a-1) << '\n';
        }
    }
}