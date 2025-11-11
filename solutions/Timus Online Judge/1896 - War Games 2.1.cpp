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

    FenwickTree(const vector<T>& v) : FenwickTree(v.size()) {
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

    int lower_bound(T val) {
        int pos = 0;
        T sum = 0;
        for(int i = __lg(n); i >= 0; i--) {
            if(pos+(1<<i) <= n && sum+tree[pos+(1<<i)] < val) {
                sum += tree[pos+(1<<i)];
                pos += 1<<i;
            }
        }
        return pos+1;
    }
};

int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    FenwickTree<int> ft(n);
    for(int i = 1; i <= ft.n; i++) {
        ft.tree[i] += 1;
        if(i+(i&-i) <= ft.n) {
            ft.tree[i+(i&-i)] += ft.tree[i];
        }
    }

    int ans = 0;

    int ord = k-1;
    int i = 1;
    while(n > 0) {
        int curr = ft.lower_bound(ord+1);
        ans ^= abs(i-curr);

        ft.sum(curr, -1);
        n--;
        if(n > 0) ord = (ord+k-1) % n;
        i++;
    }
    cout << ans << '\n';
}