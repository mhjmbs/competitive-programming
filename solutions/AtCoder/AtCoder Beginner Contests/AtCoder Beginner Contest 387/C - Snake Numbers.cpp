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

vector<vector<vector<ll>>> memo(20, vector<vector<ll>>(11, vector<ll>(2, -1)));

ll dp(int i, string& num, int fd, bool lim) {
    if(memo[i][fd][lim] != -1) return memo[i][fd][lim];

    if(i == num.size()) {
        if(fd == 10) return 0;
        return 1;
    }

    ll ans = 0;

    if(lim) {

        int max = num[i]-'0';
        if(fd != 10) max = min(max,fd-1);
 
        for(int d = 0; d <= max; d++) {
            if(fd == 10) {
                if(d == 0) ans += dp(i+1, num, 10, 0);
                else if(d == num[i]-'0') ans += dp(i+1, num, d, 1);
                else ans += dp(i+1, num, d, 0);
            }else {
                if(d == num[i]-'0') ans += dp(i+1, num, fd, 1);
                else ans += dp(i+1, num, fd, 0);
            }
        }
    }else {

        int max = (fd != 10) ? fd-1 : 9;

        for(int d = 0; d <= max; d++) {
            if(fd == 10) {
                if(d == 0) ans += dp(i+1, num, 10, 0);
                else ans += dp(i+1, num, d, 0);
            }else {
                ans += dp(i+1, num, fd, 0);
            }
        }
    }
    
    return memo[i][fd][lim] = ans;
}

int main() {
    fastio;
    
    ll l, r;
    cin >> l >> r;
    l--;
    
    string ls = to_string(l);
    string rs = to_string(r);
    
    ll ans_l = dp(0, ls, 10, 1);
    memo.assign(20, vector<vector<ll>>(11, vector<ll>(2, -1)));
    ll ans_r = dp(0, rs, 10, 1);

    cout << ans_r - ans_l << '\n';
}