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

    double th;
    int  n;
    cin >> th >> n;

    th = 2*asin(1)*th/180;

    vector<pii> v(n);
    vector<int> x(n), h(n);

    for(auto& [xi, hi] : v) cin >> xi >> hi;
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++) {
        x[i] = v[i].first;
        h[i] = v[i].second;
    }

    double ch = h[0], ans = 0;

    for(int i = 1; i < n; i++) {
        if(x[i] - x[i-1] >= ch/tan(th)) {
            ans += ch/tan(th);
            ch = h[i];
        }else {
            ans += x[i] - x[i-1];
            double nh = ch - tan(th)*(x[i] - x[i-1]);
            if(nh >= h[i]) ch = nh;
            else ch = h[i];
        }
    }
    
    ans += ch/tan(th);

    cout << setprecision(15) << ans << '\n';
}