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

    int n, k;
    cin >> n >> k;

    vector<int> a(n), freq(1e6+1);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    vector<int> mult(1e6+1);

    for(int i = 1; i <= 1e6; i++) {
        for(int j = i; j <= 1e6; j += i) {
            mult[i] += freq[j];
        }
    }

    vector<int> ans(1e6+1, 1);

    for(int i = 1; i <= 1e6; i++) {
        if(mult[i] >= k) ans[i] = i;
        for(int j = i; j <= 1e6; j += i) {
            if(mult[j] >= k) ans[j] = j;
            else if(mult[i] >= k) ans[j] = i;
        }
    }

    for(int ai : a) {
        cout << ans[ai] << '\n';
    }
}
