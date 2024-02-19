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
    vector<ull> seg, lazy;
    int leafsBegin;
    int leafsCount;

    SegmentTree(int n) : leafsCount{1} {
        while(n > leafsCount) leafsCount *= 2;
        seg.resize(2*leafsCount-1, 0);
        lazy.resize(seg.size(), 0);
        leafsBegin = seg.size() - leafsCount;
    }

    void unlazy(int i) {
        seg[i] += lazy[i];
        if(i < leafsBegin) {
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }

    void upd(int l, int r, ull val) {
        upd(l, r, val, 0, leafsCount-1, 0);
    }

    void upd(int l, int r, ull val, int lx, int rx, int i) {
        int mid = (lx+rx)/2;
        if(rx < l || r < lx) return;
        if(l <= lx && rx <= r) lazy[i] += val;
        else upd(l, r, val, lx, mid, 2*i+1), upd(l, r, val, mid+1, rx, 2*i+2);
    }

    void unlazyAll() {
        for(int i = 0; i < seg.size(); i++) unlazy(i);
    }
};

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        SegmentTree seg(n);

        for(int i = 0; i < n; i++) {
            int digit = s[i]-'0';
            seg.upd(0, n-i-1, digit);
        }

        seg.unlazyAll();

        vector<ull> ans(seg.seg.begin()+seg.leafsBegin, seg.seg.begin()+seg.leafsBegin+n);
    
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i] >= 10) {
                if(i+1 != ans.size()) ans[i+1] += ans[i]/10;
                else ans.push_back(ans[i]/10);
                ans[i] = ans[i] % 10;
            }
        }

        while(ans.back() == 0) ans.pop_back();

        for(int i = ans.size()-1; i >= 0; i--) cout << ans[i];
        cout << '\n';
    }
}