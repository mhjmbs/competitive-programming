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
struct SegmentTree {
    vector<T> seg, lazy;
    int leafsBegin;
    int leafsCount;
    
    SegmentTree(int n) {
        leafsCount = 1;
        while(leafsCount < n) leafsCount *= 2;
        seg.resize(2*leafsCount-1, 0);
        lazy.resize(seg.size(), 0);

        leafsBegin = seg.size() - leafsCount;
    }

    void sum(int l, int r, T val) {
        sum(l, r, val, 0, leafsCount-1, 0);
    }

    void sum(int l, int r, T val, int lx, int rx, int i) {
        int mid = (lx+rx)/2;
        if(rx < l || r < lx) return;
        if(l <= lx && rx <= r) lazy[i] += val;
        else sum(l, r, val, lx, mid, 2*i+1), sum(l, r, val, mid+1, rx, 2*i+2);
    }

    void unlazy(int i) {
        seg[i] += lazy[i];
        if(i < leafsBegin) {
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }

    T get(int i) {
        return get(i, 0, leafsCount-1, 0);
    }

    T get(int i, int lx, int rx, int segI) {
        unlazy(segI);
        if(lx == rx) return seg[segI];
        int mid = (lx+rx)/2;
        if(i <= mid) return get(i, lx, mid, 2*segI+1);
        return get(i, mid+1, rx, 2*segI+2);
    }
};

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        ll n, b, x;
        cin >> n >> b >> x;

        vector<ll> c(n);
        ll k = 0;
        for(ll& ci : c) {
            cin >> ci;
            k = max(k, ci);
        }

        SegmentTree<ll> seg(k+1);

        for(ll ci : c) {
            for(int i = 1; i < ci; i++) {
                ll ans = (i * (ci/i) * (i-1) * (ci/i))/2;
                ans += (ci%i * (ci%i-1))/2;
                ans += (ci%i * (i-1) * (ci/i));
                seg.sum(i, i, b*ans);
            }

            seg.sum(ci, k, b*(ci * (ci-1))/2);
        }

        ll ans = 0;
        for(int i = 1; i <= k; i++) {
            ans = max(ans, seg.get(i) - (i-1)*x);
        }

        cout << ans << '\n';
    }
}