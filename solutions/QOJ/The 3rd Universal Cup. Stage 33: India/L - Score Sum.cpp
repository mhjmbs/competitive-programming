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

struct SegmentTree {
    vector<ll> seg, lazy_sum, lazy_set;
    int leafs_begin, leafs_count;

    SegmentTree(int n) : leafs_count{1} {
        while(leafs_count < n) leafs_count *= 2;
        seg.assign(2*leafs_count-1, 0);
        lazy_sum.assign(2*leafs_count-1, 0);
        lazy_set.assign(2*leafs_count-1, -1);
        leafs_begin = seg.size() - leafs_count;
    }

    void unlazy_set(int i, int l, int r) {
        if(lazy_set[i] == -1) return;
        seg[i] = (r-l+1)*lazy_set[i];

        if(i < leafs_begin) {
            lazy_sum[2*i+1] = 0;
            lazy_sum[2*i+2] = 0;
            lazy_set[2*i+1] = lazy_set[i];
            lazy_set[2*i+2] = lazy_set[i];
        }

        lazy_set[i] = -1;
    }

    void unlazy_sum(int i, int l, int r) {
        unlazy_set(i, l, r);
        seg[i] += (lazy_sum[i])*(r-l+1);
        if(i < leafs_begin) {
            int mid = (l+r)/2;
            unlazy_set(2*i+1, l, mid);
            unlazy_set(2*i+2, mid+1, r);
            lazy_sum[2*i+1] += lazy_sum[i];
            lazy_sum[2*i+2] += lazy_sum[i];
        }
        lazy_sum[i] = 0;
    }

    void sum(int l, int r, ll val) {
        sum(l, r, 0, leafs_count-1, val, 0);
    }

    void sum(int l, int r, int lx, int rx, ll val, int i) {
        unlazy_sum(i, lx, rx);
        if(rx < l || r < lx) return;
        if(l <= lx && rx <= r) {
            lazy_sum[i] += val;
            unlazy_sum(i, lx, rx);
        }else {
            int mid = (lx+rx)/2;
            sum(l, r, lx, mid, val, 2*i+1);
            sum(l, r, mid+1, rx, val, 2*i+2);
            seg[i] = seg[2*i+1] + seg[2*i+2];
        }
    }

    void set(int l, int r, ll val) {
        set(l, r, 0, leafs_count-1, val, 0);
    }

    void set(int l, int r, int lx, int rx, ll val, int i) {
        unlazy_sum(i, lx, rx);
        if(rx < l || r < lx) return;
        if(l <= lx && rx <= r) {
            lazy_set[i] = val;
            unlazy_sum(i, lx, rx);
        }else {
            int mid = (lx+rx)/2;
            set(l, r, lx, mid, val, 2*i+1);
            set(l, r, mid+1, rx, val, 2*i+2);
            seg[i] = seg[2*i+1] + seg[2*i+2];
        }
    }

    ll get(int i) {
        return query(i, i);
    }

    ll query(int l, int r) {
        return query(l, r, 0, leafs_count-1, 0);
    }

    ll query(int l, int r, int lx, int rx, int i) {
        unlazy_sum(i, l, r);
        if(rx < l || r < lx) return 0;
        if(l <= lx && rx <= r) return seg[i];
        int mid = (lx+rx)/2;
        return query(l, r, lx, mid, 2*i+1) + query(l, r, mid+1, rx, 2*i+2); 
    }
};

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;

        vector<ll> a(n);
        for(ll& ai : a) cin >> ai;

        SegmentTree r(n);
        vector<int> last(n+1, -1), freq(n+1, 0);
        ll sum_r = 0;

        for(int i = 0, ld = 0; i < n; i++) {
            r.set(0, last[a[i]],i);
            freq[a[i]]++;
            while(freq[a[i]] > 1) {
                freq[a[ld]]--;
                ld++;
            }
            r.set(ld,i,i);
            sum_r += r.query(0,i);
            last[a[i]] = i;
        }

        SegmentTree l(n);
        vector<int> first(n+1, n);
        ll sum_l = 0;
        for(int i = n-1; i >= 0; i--) {
            l.set(first[a[i]], n-1, i);
            l.set(i,i,i);
            sum_l += l.query(i,n-1);
            first[a[i]] = i;
        }

        cout << sum_r - sum_l + n*(n-1)/2 + n << '\n';
    }
}