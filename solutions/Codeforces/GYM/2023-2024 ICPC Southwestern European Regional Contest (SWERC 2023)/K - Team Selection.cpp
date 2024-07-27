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

struct bit {
    int n;
    vector<int> b;

    bit(const vector<int>& v) : n(v.size()), b(n+1, 0) {
        for(int i = 1; i <= n; i++) {
            b[i] += v[i-1];
            if(i + lsb(i) <= n) {
                b[i+lsb(i)] += b[i];
            }
        }
    }

    void add(int i, int val) {
        while(i <= n) {
            b[i] += val;
            i += lsb(i);
        }
    }

    int query(int k) {
        int sum = 0, ans = 0;
        int i = 1;

        while(i <= n) {
            if(i+lsb(i) <= n && sum+b[i+lsb(i)] < k) {
                i += lsb(i);
            }else if(sum+b[i] < k) {
                sum += b[i];
                ans = i;
                i++;
            }else {
                break;
            }
        }

        return ans+1;
    }

    int lsb(int x) {
        return x&-x;
    }
};

int main() {
    fastio;

    int n;
    cin >> n;

    vector<int> a(n/2), b(n/2);
    for(int& ai : a) cin >> ai;
    for(int& bi : b) cin >> bi;

    bit bt(vector<int>(n,1));

    vector<int> x(n/2), y(n/2);

    for(int i = 0; i < n/2; i++) {
        x[i] = bt.query(a[i]);
        bt.add(x[i],-1);
        y[i] = bt.query(b[i]);
        bt.add(y[i],-1);
    }

    for(int xi : x) cout << xi << ' ';
    cout << '\n';
    for(int yi : y) cout << yi << ' ';
    cout << '\n';
}