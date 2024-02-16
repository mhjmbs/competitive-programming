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
struct BIT {
    vector<T> bit;

    BIT(vector<T>& v) : bit(v.size()+1, 0) {
        for(int i = 1; i < bit.size(); i++) {
            if(i == 1) bit[i] += v[i-1];
            else bit[i] += v[i-1] - v[i-2];
            if(i+(i&-i) < bit.size()) bit[i+(i&-i)] += bit[i];
        }
    }

    void sum(int i, T val) {
        while(i < bit.size()) {
            bit[i] += val;
            i += i&-i;
        }
    }

    T get(int i) {
        T ans = 0;
        while(i > 0) {
            ans += bit[i];
            i -= i&-i;
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

    BIT<ll> bit(x);

    while(q--) {
        int tq;
        cin >> tq;

        if(tq == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            bit.sum(a, u);
            bit.sum(b+1, -u);
        }else {
            int k;
            cin >> k;
            cout << bit.get(k) << '\n';
        }
    }
}