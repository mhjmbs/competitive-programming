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
using pdd = pair<double,double>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

pll transf(int x, int y) {
    return {x-y, x+y};
}

ll solve(vector<ll>& x, vector<ll>& y) {
    vector<ll> diffX(x.size(),0), diffY(y.size(),0);
    for(int i = 1; i < x.size(); i++) {
        diffX[i] = x[i] - x[i-1];
        diffY[i] = y[i] - y[i-1];
    }

    ll ans = 0;

    for(int i = 1; i < x.size(); i++) {
        ans += diffX[i]*i*(x.size()-i);
        ans += diffY[i]*i*(x.size()-i);
    }

    return ans/2;
}

int main() {
    fastio;

    int n;
    cin >> n;

    vector<ll> x1, y1, x2, y2;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        auto [x3,y3] = transf(x,y);

        if((x%2==0 && y%2==0) || (x%2==1 && y%2==1)) {
            x1.push_back(x3);
            y1.push_back(y3);
        }else {
            x2.push_back(x3);
            y2.push_back(y3);
        }
    }

    sort(x1.begin(), x1.end());
    sort(y1.begin(), y1.end());
    sort(x2.begin(), x2.end());
    sort(y2.begin(), y2.end());

    ll ans = 0;
    
    ans += solve(x1,y1);
    ans += solve(x2,y2);

    cout << ans << '\n';
}