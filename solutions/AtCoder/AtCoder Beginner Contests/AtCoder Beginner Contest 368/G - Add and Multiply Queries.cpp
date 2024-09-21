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

struct SegmentTree {
    vector<ll> seg;
    int leafs_begin, leafs_count;

    SegmentTree(int n) {
        leafs_count = 1;
        while(leafs_count < n) leafs_count *= 2;
        seg.resize(2*leafs_count - 1);
        leafs_begin = seg.size() - leafs_count;
    }

    SegmentTree(vector<ll>& v) : SegmentTree(v.size()) {
        for(int i = 0; i < v.size(); i++) {
            seg[leafs_begin+i] = v[i];
        }
        for(int i = leafs_begin-1; i >= 0; i--) {
            seg[i] = seg[2*i+1] + seg[2*i+2];
        }
    }

    void upd(int i, ll val) {
        i += leafs_begin;
        seg[i] = val;
        while(i > 0) {
            i = (i-1)/2;
            seg[i] = seg[2*i+1] + seg[2*i+2];
        }
    }

    ll query(int l, int r) {
        return query(l, r, 0, leafs_count-1, 0);   
    }

    ll query(int l, int r, int lx, int rx, int i) {
        if(r < lx || rx < l) return 0;
        if(l <= lx && rx <= r) return seg[i];
        int mid = (lx+rx)/2;
        return query(l, r, lx, mid, 2*i+1) + query(l, r, mid+1, rx, 2*i+2);
    }
};

int main() {
    fastio;

    int n;
    cin >> n;

    vector<ll> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    SegmentTree seg(a);

    set<int> b_pos;
    for(int i = 1; i <= n; i++) {
        if(b[i] != 1) b_pos.insert(i);
    }

    int q;
    cin >> q;

    while(q--) {
        int tq;
        cin >> tq;

        if(tq == 1) {
            int i, x;
            cin >> i >> x;
            seg.upd(i, x);
        }else if(tq == 2) {
            int i, x;
            cin >> i >> x;
            if(x == 1) b_pos.erase(i);
            else b_pos.insert(i);
            b[i] = x;
        }else {
            int l, r;
            cin >> l >> r;

            ll ans = seg.query(l,l);
            l++;

            while(l <= r) {
                auto it = b_pos.lower_bound(l);
                int r1 = r;
                if(it != b_pos.end()) r1 = min(r, *it - 1);

                ans += seg.query(l, r1);

                if(r1+1 <= r) ans = max(ans+seg.query(r1+1,r1+1), ans*b[r1+1]);

                l = r1+2;
            }

            cout << ans << '\n';
        }
    }
}