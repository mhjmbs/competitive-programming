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

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<int> a(n), b(m);
    for(int& ai : a) cin >> ai;
    for(int& bi : b) cin >> bi;

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    vector<int> cnt(n);

    int big = 0, best = 0;

    for(int i = 0; i < m; i++) {
        if(best < n && b[i] <= a[best]) {
            cnt[best]++;
            if(cnt[best] == y) best++;
        }else if(big < n && b[i] <= a[big]) {
            cnt[big]++;
            if(cnt[big] == x) big++;
        }else {
            cout << "impossible\n";
            return 0;
        }
    }

    cout << count_if(cnt.begin(), cnt.end(), [y](int x) {return x <= y;}) << '\n';
}