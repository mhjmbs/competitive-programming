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

    int n;
    cin >> n;

    vector<int> a(n);
    for(int& ai : a) cin >> ai;

    map<int,int> a1, a2;

    for(int ai : a) a2[ai]++;

    int ans = -1;

    for(int i = 0; i < n-1; i++) {
        a1[a[i]]++;
        a2[a[i]]--;
        if(a2[a[i]] == 0) a2.erase(a[i]);
        ans = max(ans, int(a1.size() + a2.size()));
    }

    cout << ans << '\n';
}