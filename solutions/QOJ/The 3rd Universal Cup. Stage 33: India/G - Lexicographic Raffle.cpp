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

    int t;
    cin >> t;

    while(t--) {
        int n, q;
        cin >> n >> q;

        string s;
        cin >> s;

        vector<int> nx(n, n);
        
        for(int i = n-2; i >= 0; i--) {
            if(s[i] < s[i+1]) nx[i] = i;
            else nx[i] = nx[i+1];
        }

        vector<int> le(n);
        iota(le.begin(), le.end(), 0);

        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) le[i] = le[i-1];
        }

        while(q--) {
            int l, r;
            cin >> l >> r;
            l--, r--;

            cout << max(l, le[min(r, nx[l])]) + 1 << '\n';
        }
    }
}