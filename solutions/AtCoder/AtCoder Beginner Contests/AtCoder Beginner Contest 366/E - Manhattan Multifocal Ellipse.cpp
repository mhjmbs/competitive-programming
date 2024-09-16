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



int main() {
    fastio;

    int n,d;
    cin >> n >> d;

    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int x0 = x.back()-d, xn = x.front()+d;
    ll xSum = 0;
    for(int i = 0; i < n; i++) xSum += abs(x0 - x[i]);

    vector<ll> xSums, ySums;

    for(; x0 <= xn; x0++) {
        xSums.push_back(xSum);
        int right = x.end() - upper_bound(x.begin(), x.end(), x0);
        int left = n - right;
        xSum += left - right;
    }

    int y0 = y.back()-d, yn = y.front()+d;
    ll ySum = 0;
    for(int i = 0; i < n; i++) ySum += abs(y0 - y[i]);

    for(; y0 <= yn; y0++) {
        ySums.push_back(ySum);
        int right = y.end() - upper_bound(y.begin(), y.end(), y0);
        int left = n - right;
        ySum += left - right;
    }

    sort(xSums.begin(), xSums.end());
    sort(ySums.begin(), ySums.end());

    ll ans = 0;

    for(int xSum : xSums) {
        ans += upper_bound(ySums.begin(), ySums.end(), d-xSum) - ySums.begin();
    }

    cout << ans << '\n';
}