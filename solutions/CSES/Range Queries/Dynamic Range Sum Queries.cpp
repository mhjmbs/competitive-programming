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

template<typename T>
struct FenwickTree {
    int n;
    vector<T> tree;

    FenwickTree(int n) : n{n}, tree(n+1) 
    {}

    FenwickTree(vector<T>& v) : FenwickTree(v.size()) {
        for(int i = 1; i <= n; i++) {
            tree[i] += v[i-1];
            if(i+(i&-i) <= n) {
                tree[i+(i&-i)] += tree[i];
            }
        }
    }

    void sum(int i, T val) {
        while(i <= n) {
            tree[i] += val;
            i += i&-i;
        }
    }

    T query(int l, int r) {
        return query(r) - query(l-1);
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
    for(ll& xi : x) cin >> xi;

    FenwickTree<ll> ft(x);

    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int k, u;
            cin >> k >> u;
            ft.sum(k, u-x[k-1]);
            x[k-1] = u;
        }else {
            int a, b;
            cin >> a >> b;
            cout << ft.query(a,b) << '\n';
        }
    }
}