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



int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    vector<int> g(n+1);

    for(int r = 0; r < m; r++) {
        int x, y;
        cin >> x >> y;
    
        vector<int> a(n+1);
        for(int i = 0; i < n; i++) cin >> a[i];

        int cnt1 = count(a.begin(), a.end(), 1);

        if(x/(cnt1+1) >= y) {
            cnt1++;
            a[n] = 1;
        }else {
            a[n] = 2;
        }

        for(int i = 0; i <= n; i++) {
            g[i] += (a[i] == 1) ? x/cnt1 : y; 
        }
    }

    for(int gi : g) cout << gi << ' ';
    cout << '\n';
}