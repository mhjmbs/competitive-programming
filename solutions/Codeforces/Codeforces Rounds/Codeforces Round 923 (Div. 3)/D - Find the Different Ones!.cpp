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

struct segtreeMax {
    int lrStart;
    int lrSize = 1;
    vector<pii> st;
 
    segtreeMax(vector<int>& a) {
        setSize(a.size());
        lrStart = st.size() - lrSize;
 
        for(int i = lrStart; i - lrStart < a.size(); i++) {
            st[i] = {a[i - lrStart], i-lrStart};
        }
        
        for(int i = lrStart-1; i >= 0; i--) {
            st[i] = max(st[2*i+1], st[2*i+2]);
        }
    }
 
    void setSize(int initSize) {
        while(lrSize < initSize) {
            lrSize *= 2;
        }
 
        st.resize(2*lrSize - 1, {INT_MIN,-1});
    }
 
    pii query(int l, int r, int lx = 0, int rx = -1, int i = 0) {
        if(rx == -1) {
            rx = lrSize-1;
        }
 
        if(l <= lx && rx <= r) {
            return st[i];
        }else if(rx < l || r < lx) {
            return {INT_MIN,-1};
        }else {
            int m = lx + (rx-lx)/2;
            return max(query(l, r, lx, m, 2*i+1), query(l, r, m+1, rx, 2*i+2));
        }
    }
};

struct segtreeMin {
    int lrStart;
    int lrSize = 1;
    vector<pii> st;
 
    segtreeMin(vector<int>& a) {
        setSize(a.size());
        lrStart = st.size() - lrSize;
 
        for(int i = lrStart; i - lrStart < a.size(); i++) {
            st[i] = {a[i - lrStart], i-lrStart};
        }
        
        for(int i = lrStart-1; i >= 0; i--) {
            st[i] = min(st[2*i+1], st[2*i+2]);
        }
    }
 
    void setSize(int initSize) {
        while(lrSize < initSize) {
            lrSize *= 2;
        }
 
        st.resize(2*lrSize - 1, {INT_MAX,-1});
    }
 
    pii query(int l, int r, int lx = 0, int rx = -1, int i = 0) {
        if(rx == -1) {
            rx = lrSize-1;
        }
 
        if(l <= lx && rx <= r) {
            return st[i];
        }else if(rx < l || r < lx) {
            return {INT_MAX,-1};
        }else {
            int m = lx + (rx-lx)/2;
            return min(query(l, r, lx, m, 2*i+1), query(l, r, m+1, rx, 2*i+2));
        }
    }
};

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int& ai : a) cin >> ai;

        segtreeMin segMin(a);
        segtreeMax segMax(a);

        int q;
        cin >> q;

        while(q--) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;

            pii inMax = segMax.query(l,r);
            pii inMin = segMin.query(l,r);

            if(inMax.first == inMin.first) cout << -1 << ' ' << -1 << '\n';
            else cout << min(inMax.second,inMin.second)+1 << ' ' << max(inMax.second, inMin.second)+1 << '\n';
        }
    }
}