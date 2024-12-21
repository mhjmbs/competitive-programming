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

int mod(int a, int m) {
    return (a % m + m) % m; 
}

int mex(vector<int> v) {
    int ans = 0;
    sort(v.begin(), v.end());

    for(int vi : v) {
        if(vi == ans) ans++;
    }

    return ans;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n, x, y;
        cin >> n >> x >> y;
        x--,y--;
        vector<int> a(n);
        for(int i = x+1; i <= y; i++) a[i] = !a[i-1];

        if((x-y+1) % 2 != 0) a[y] = 2;

        for(int i = mod(x-1,n); i != y; i = mod(i-1,n)) a[i] = !a[mod(i+1,n)];

        if(a[mod(y+1,n)] == 1) a[y] = 2;

        for(int ai : a) cout << ai << ' ';
        cout << '\n';
    }
}