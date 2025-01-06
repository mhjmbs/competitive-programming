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

struct SegmentTree1 {
    vector<ll> seg_min, seg_max, ans;
    int leafsBegin;
    int leafsCount;

    SegmentTree1(const vector<ll>& v) {
        leafsCount = 1;
        while(leafsCount < v.size()) leafsCount *= 2;
        
        seg_min.resize(2*leafsCount-1, 1e16);
        seg_max.resize(2*leafsCount-1, -1e16);
        ans.resize(2*leafsCount-1, -1e16);
        
        leafsBegin = seg_min.size() - leafsCount;

        for(int i = 0; i < v.size(); i++) {
            seg_min[leafsBegin+i] = seg_max[leafsBegin+i] = v[i];
            ans[leafsBegin+i] = 0;
        }

        for(int i = leafsBegin-1; i >= 0; i--) {
            seg_min[i] = min(seg_min[2*i+1], seg_min[2*i+2]);
            seg_max[i] = max(seg_max[2*i+1], seg_max[2*i+2]);
            ans[i] = max({ans[2*i+1], ans[2*i+2], seg_max[2*i+2] - seg_min[2*i+1]});
        }
    }

    void upd(int i, ll val) {
        i = leafsBegin + i;
        seg_min[i] = seg_max[i] = val;
        while(i > 0) {
            i = (i-1)/2;
            seg_min[i] = min(seg_min[2*i+1], seg_min[2*i+2]);
            seg_max[i] = max(seg_max[2*i+1], seg_max[2*i+2]);
            ans[i] = max({ans[2*i+1], ans[2*i+2], seg_max[2*i+2] - seg_min[2*i+1]});
        }
    }

    ll query() {
        return ans[0];
    }
};

struct SegmentTree2 {
    vector<ll> seg_min, seg_max, ans;
    int leafsBegin;
    int leafsCount;

    SegmentTree2(const vector<ll>& v) {
        leafsCount = 1;
        while(leafsCount < v.size()) leafsCount *= 2;
        
        seg_min.resize(2*leafsCount-1, 1e16);
        seg_max.resize(2*leafsCount-1, -1e16);
        ans.resize(2*leafsCount-1, -1e16);
        
        leafsBegin = seg_min.size() - leafsCount;

        for(int i = 0; i < v.size(); i++) {
            seg_min[leafsBegin+i] = seg_max[leafsBegin+i] = v[i];
            ans[leafsBegin+i] = 0;
        }

        for(int i = leafsBegin-1; i >= 0; i--) {
            seg_min[i] = min(seg_min[2*i+1], seg_min[2*i+2]);
            seg_max[i] = max(seg_max[2*i+1], seg_max[2*i+2]);
            ans[i] = max({ans[2*i+1], ans[2*i+2], seg_max[2*i+1] - seg_min[2*i+2]});
        }
    }

    void upd(int i, ll val) {
        i = leafsBegin + i;
        seg_min[i] = seg_max[i] = val;
        while(i > 0) {
            i = (i-1)/2;
            seg_min[i] = min(seg_min[2*i+1], seg_min[2*i+2]);
            seg_max[i] = max(seg_max[2*i+1], seg_max[2*i+2]);
            ans[i] = max({ans[2*i+1], ans[2*i+2], seg_max[2*i+1] - seg_min[2*i+2]});
        }
    }

    ll query() {
        return ans[0];
    }
};

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for(int& ai : a) cin >> ai;

        vector<ll> a1(n), a2(n);
        for(int i = 0; i < n; i++) {
            a1[i] = a[i]-i;
            a2[i] = a[i]+i;
        }

        SegmentTree1 seg1(a1);
        SegmentTree2 seg2(a2);

        cout << max(seg1.query(), seg2.query()) << '\n';

        while(q--) {
            int p, x;
            cin >> p >> x;
            p--;

            seg1.upd(p, x-p);
            seg2.upd(p, x+p);

            cout << max(seg1.query(), seg2.query()) << '\n';
        }
    }
}